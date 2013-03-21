
package org.jouvieje.fileformat.wav;

import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;

import org.jouvieje.bass.misc.FileWriterUtils;

/**
 * Used to write into a wav file
 * 
 * @author J�r�me JOUVIE (Jouvieje)
 * 
 * WANT TO CONTACT ME ?
 * E-mail :
 * 		jerome.jouvie@gmail.com
 * My web sites :
 * 		http://jerome.jouvie.free.fr/
 */
public class WavHeader
{
	public final static int SIZEOF_WAV_HEADER = RiffChunk.SIZEOF_RIFF_CHUNK + 4;
	
	private RiffChunk chunk = null;
	private byte[] rifftype = null;
	
	public WavHeader(RiffChunk chunk, byte[] rifftype)
	{
		this.chunk = chunk;
		this.rifftype = rifftype;
	}
	
	public RiffChunk getChunk()
	{
		return chunk;
	}
	public void setChunk(RiffChunk chunk)
	{
		this.chunk = chunk;
	}
	
	public byte[] getRifftype()
	{
		return rifftype;
	}
	public void setRifftype(byte[] rifftype)
	{
		this.rifftype = rifftype;
	}
	
	/**
	 * Write the header of a Wav File.<BR>
	 * Before calling this method, go to the begining of the file (for example with <code>file.seek(0)</code>).
	 * @param file file to write in.
	 * @param wavHeader a <code>WavHeader</code> object.
	 */
	public static void writeWavHeader(RandomAccessFile file, WavHeader wavHeader) throws IOException
	{
		RiffChunk.writeRiffChunk(file, wavHeader.getChunk());
		FileWriterUtils.writeByteArray(file, wavHeader.getRifftype());
	}
	public static void putWavHeader(ByteBuffer buffer, WavHeader wavHeader)
	{
		RiffChunk.putRiffChunk(buffer, wavHeader.getChunk());
		buffer.put(wavHeader.getRifftype());
	}
}