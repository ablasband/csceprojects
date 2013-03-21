/**
 * 						NativeBass Project
 *
 * Want to use BASS (www.un4seen.com) in the Java language ? NativeBass is made for you.
 * Copyright © 2007-2009 Jérôme JOUVIE (Jouvieje)
 *
 * Created on 02 jul. 2007
 * @version file v1.0.6
 * @author Jérôme JOUVIE (Jouvieje)
 * 
 * 
 * WANT TO CONTACT ME ?
 * E-mail :
 * 		jerome.jouvie@gmail.com
 * My web sites :
 * 		http://jerome.jouvie.free.fr/
 * 
 * 
 * INTRODUCTION
 * BASS is an audio library for use in Windows and Mac OSX software.
 * Its purpose is to provide developers with the most powerful and
 * efficient (yet easy to use), sample, stream (MP3, MP2, MP1, OGG, WAV, AIFF,
 * custom generated, and more via add-ons), MOD music (XM, IT, S3M, MOD, MTM, UMX),
 * MO3 music (MP3/OGG compressed MODs),
 * and recording functions. All in a tiny DLL, under 100KB* in size.
 * 
 * BASS official web site :
 * 		http://www.un4seen.com/
 * 
 * 
 * GNU LESSER GENERAL PUBLIC LICENSE
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of the License,
 * or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the
 * Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307 USA 
 */

package org.jouvieje.bass.structures;

import org.jouvieje.bass.*;
import org.jouvieje.bass.exceptions.*;
import org.jouvieje.bass.callbacks.*;
import org.jouvieje.bass.*;
import org.jouvieje.bass.defines.*;
import org.jouvieje.bass.enumerations.*;
import org.jouvieje.bass.structures.*;
import java.nio.*;
import org.jouvieje.bass.*;
import org.jouvieje.bass.enumerations.*;
import org.jouvieje.bass.structures.*;
import org.jouvieje.bass.misc.*;

/**
 * User file stream callback functions
 */
public class BASS_FILEPROCS extends Pointer
{
	/**
	 * Create a view of the <code>Pointer</code> object as a <code>BASS_FILEPROCS</code> object.<br>
	 * This view is valid only if the memory holded by the <code>Pointer</code> holds a BASS_FILEPROCS object.
	 */
	public static BASS_FILEPROCS createView(Pointer pointer)
	{
		return new BASS_FILEPROCS(Pointer.getPointer(pointer));
	}
	/**
	 * Create a new <code>BASS_FILEPROCS</code>.<br>
	 * The call <code>isNull()</code> on the object created will return false.<br>
	 * <pre><code>  BASS_FILEPROCS obj = BASS_FILEPROCS.create();
	 *  (obj == null) <=> obj.isNull() <=> false
	 * </code></pre>
	 */
	public static BASS_FILEPROCS create()
	{
		return new BASS_FILEPROCS(StructureJNI.BASS_FILEPROCS_new());
	}

	protected BASS_FILEPROCS(long pointer)
	{
		super(pointer);
	}

	/**
	 * Create an object that holds a null <code>BASS_FILEPROCS</code>.<br>
	 * The call <code>isNull()</code> on the object created will returns true.<br>
	 * <pre><code>  BASS_FILEPROCS obj = new BASS_FILEPROCS();
	 *  (obj == null) <=> false
	 *  obj.isNull() <=> true
	 * </code></pre>
	 * To creates a new <code>BASS_FILEPROCS</code>, use the static "constructor" :
	 * <pre><code>  BASS_FILEPROCS obj = BASS_FILEPROCS.create();</code></pre>
	 * @see BASS_FILEPROCS#create()
	 */
	public BASS_FILEPROCS()
	{
		super();
	}

	public void release()
	{
		if(pointer != 0)
		{
			CallbackManager.addCallback(1, null, pointer);
			CallbackManager.addCallback(2, null, pointer);
			CallbackManager.addCallback(3, null, pointer);
			CallbackManager.addCallback(4, null, pointer);
			CallbackManager.addOwner(0, pointer);
			StructureJNI.BASS_FILEPROCS_delete(pointer);
		}
		pointer = 0;
	}

	/**
	 * 
	 */
	public FILECLOSEPROC getClose()
	{
		if(pointer == 0) throw new NullPointerException();
		return (FILECLOSEPROC)CallbackManager.getCallback(1, pointer, false);
	}
	public void setClose(FILECLOSEPROC close)
	{
		if(pointer == 0) throw new NullPointerException();
		CallbackManager.addCallback(1, close, pointer);
		StructureJNI.BASS_FILEPROCS_set_close(pointer, close != null);
	}

	/**
	 * 
	 */
	public FILELENPROC getLength()
	{
		if(pointer == 0) throw new NullPointerException();
		return (FILELENPROC)CallbackManager.getCallback(2, pointer, false);
	}
	public void setLength(FILELENPROC length)
	{
		if(pointer == 0) throw new NullPointerException();
		CallbackManager.addCallback(2, length, pointer);
		StructureJNI.BASS_FILEPROCS_set_length(pointer, length != null);
	}

	/**
	 * 
	 */
	public FILEREADPROC getRead()
	{
		if(pointer == 0) throw new NullPointerException();
		return (FILEREADPROC)CallbackManager.getCallback(3, pointer, false);
	}
	public void setRead(FILEREADPROC read)
	{
		if(pointer == 0) throw new NullPointerException();
		CallbackManager.addCallback(3, read, pointer);
		StructureJNI.BASS_FILEPROCS_set_read(pointer, read != null);
	}

	/**
	 * 
	 */
	public FILESEEKPROC getSeek()
	{
		if(pointer == 0) throw new NullPointerException();
		return (FILESEEKPROC)CallbackManager.getCallback(4, pointer, false);
	}
	public void setSeek(FILESEEKPROC seek)
	{
		if(pointer == 0) throw new NullPointerException();
		CallbackManager.addCallback(4, seek, pointer);
		StructureJNI.BASS_FILEPROCS_set_seek(pointer, seek != null);
	}

}