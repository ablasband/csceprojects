/*
 * Created on 11 sept. 07
 */
package org.jouvieje.bass.examples;

import static org.jouvieje.bass.Bass.*;
import static org.jouvieje.bass.defines.BASS_DEVICE.BASS_DEVICE_3D;

import static org.jouvieje.bass.examples.util.Device.*;

import java.awt.Dimension;
import java.awt.Frame;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

import org.jouvieje.bass.structures.BASS_DEVICEINFO;

public class OutputDevice extends JDialog
{
	public int getSelectedDevice()
	{
		return ((DeviceItem)getDevices().getSelectedValue()).device;
	}
	
	class DeviceItem
	{
		public String name;
		public int device;
		public DeviceItem(String name, int device)
		{
			this.name = name;
			this.device = device;
		}
		public String toString() { return name; }
	}
	
	private static final long serialVersionUID = 1L;
	private JPanel jContentPane = null;
	private JScrollPane devicesSP = null;
	private JList devices = null;
	private JButton approve = null;

	public OutputDevice()
	{
		super((Frame)null, true);	//FIXME
		initialize();
	}
	private void initialize()
	{
		this.setSize(261, 136);
		this.setPreferredSize(new Dimension(261, 136));
		this.setTitle("BASS output device selector");
		this.setLocationRelativeTo(null);
		this.setContentPane(getJContentPane());
		this.setResizable(false);
		this.setDefaultCloseOperation(JDialog.DO_NOTHING_ON_CLOSE);
	}
	private JPanel getJContentPane()
	{
		if(jContentPane == null)
		{
			GridBagConstraints gridBagConstraints1 = new GridBagConstraints();
			gridBagConstraints1.gridx = 0;
			gridBagConstraints1.anchor = GridBagConstraints.EAST;
			gridBagConstraints1.insets = new Insets(0, 0, 5, 20);
			gridBagConstraints1.gridy = 1;
			GridBagConstraints gridBagConstraints = new GridBagConstraints();
			gridBagConstraints.fill = GridBagConstraints.BOTH;
			gridBagConstraints.gridy = 0;
			gridBagConstraints.weightx = 1.0;
			gridBagConstraints.weighty = 1.0;
			gridBagConstraints.insets = new Insets(10, 10, 5, 10);
			gridBagConstraints.gridx = 0;
			jContentPane = new JPanel();
			jContentPane.setLayout(new GridBagLayout());
			jContentPane.add(getDevicesSP(), gridBagConstraints);
			jContentPane.add(getApprove(), gridBagConstraints1);
		}
		return jContentPane;
	}
	private JScrollPane getDevicesSP()
	{
		if(devicesSP == null)
		{
			devicesSP = new JScrollPane();
			devicesSP.setViewportView(getDevices());
		}
		return devicesSP;
	}
	private JList getDevices()
	{
		if(devices == null)
		{
			DefaultListModel model = new DefaultListModel();
			BASS_DEVICEINFO info = BASS_DEVICEINFO.create();
			for(int c = 1; BASS_GetDeviceInfo(c, info); c++)
			{
				String text = info.getName();
				
				//device 1 = 1st real device
				/* Check if the device supports 3D */
				if(!BASS_Init(forceNoSoundDevice(c), forceFrequency(44100), BASS_DEVICE_3D, null, null))
					continue;	// no 3D support
				if(BASS_GetEAXParameters(null, null, null, null))
					text += " [EAX]"; // it has EAX
				BASS_Free();
				
				model.addElement(new DeviceItem(text, c));
			}
			
			devices = new JList(model);
			devices.setSelectedIndex(0);
		}
		return devices;
	}
	private JButton getApprove()
	{
		if(approve == null)
		{
			approve = new JButton();
			approve.setText("OK");
			approve.addActionListener(new java.awt.event.ActionListener(){
				public void actionPerformed(java.awt.event.ActionEvent e)
				{
					if(getDevices().getSelectedIndex() == -1)
						getDevices().setSelectedIndex(0);
					dispose();
				}
			});
		}
		return approve;
	}
}  //  @jve:decl-index=0:visual-constraint="10,10"
