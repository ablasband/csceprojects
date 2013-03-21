
package org.jouvieje.fileformat.wav;

import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;

/**
 * Used to write into a wav file
 * 
 * @author Jérôme JOUVIE (Jouvieje)
 * 
 * WANT TO CONTACT ME ?
 * E-mail :
 * 		jerome.jouvie@gmail.com
 * My web sites :
 * 		http://jerome.jouvie.free.fr/
 */
public class DataChunk
{
	public final static int SIZEOF_DATA_CHUNK = RiffChunk.SIZEOF_RIFF_CHUNK;
	
	private RiffChunk chunk = null;
	
	public DataChunk(RiffChunk chunk)
	{
		this.chunk = chunk;
	}
	
	public RiffChunk getChunk()
	{
		return chunk;
	}
	public void setChunk(RiffChunk chunk)
	{
		this.chunk = chunk;
	}
	
	/**
	 * Write a <Code>DataChunk</code> object into a file.<BR>
	 * Call this methods after <code>FmtChunk.writeFmtChunk(...)</code><BR>
	 * After writting <code>DataChunk</code>, you can write datas.
	 * @param file a file to write in.
	 * @param dataChunk a <code>DataChunk</code> object.
	 * @see FmtChunk#writeFmtChunk(RandomAccessFile, FmtChunk)
	 */
	public static void writeDataChunk(RandomAccessFile file, DataChunk dataChunk) throws IOException
	{
		RiffChunk.writeRiffChunk(file, dataChunk.getChunk());
	}
	public static void putDataChunk(ByteBuffer buffer, DataChunk dataChunk)
	{
		RiffChunk.putRiffChunk(buffer, dataChunk.getChunk());
	}
}