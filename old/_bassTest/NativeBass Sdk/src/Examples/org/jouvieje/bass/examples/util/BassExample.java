/*
 * Created on 12 janv. 08
 */
package org.jouvieje.bass.examples.util;

import javax.swing.JPanel;

public interface BassExample extends Runnable
{
	public String getTitle();
	public JPanel getPanel();
	public void stop();
}
