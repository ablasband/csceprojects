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
 * ID3v1 tag structure
 */
public class TAG_ID3 extends Pointer
{
	/**
	 * Create a view of the <code>Pointer</code> object as a <code>TAG_ID3</code> object.<br>
	 * This view is valid only if the memory holded by the <code>Pointer</code> holds a TAG_ID3 object.
	 */
	public static TAG_ID3 createView(Pointer pointer)
	{
		return new TAG_ID3(Pointer.getPointer(pointer));
	}
	/**
	 * Create a new <code>TAG_ID3</code>.<br>
	 * The call <code>isNull()</code> on the object created will return false.<br>
	 * <pre><code>  TAG_ID3 obj = TAG_ID3.create();
	 *  (obj == null) <=> obj.isNull() <=> false
	 * </code></pre>
	 */
	public static TAG_ID3 create()
	{
		return new TAG_ID3(StructureJNI.TAG_ID3_new());
	}

	protected TAG_ID3(long pointer)
	{
		super(pointer);
	}

	/**
	 * Create an object that holds a null <code>TAG_ID3</code>.<br>
	 * The call <code>isNull()</code> on the object created will returns true.<br>
	 * <pre><code>  TAG_ID3 obj = new TAG_ID3();
	 *  (obj == null) <=> false
	 *  obj.isNull() <=> true
	 * </code></pre>
	 * To creates a new <code>TAG_ID3</code>, use the static "constructor" :
	 * <pre><code>  TAG_ID3 obj = TAG_ID3.create();</code></pre>
	 * @see TAG_ID3#create()
	 */
	public TAG_ID3()
	{
		super();
	}

	public void release()
	{
		if(pointer != 0)
		{

			StructureJNI.TAG_ID3_delete(pointer);
		}
		pointer = 0;
	}

	/**
	 * 
	 */
	public String getId()
	{
		if(pointer == 0) throw new NullPointerException();
		String javaResult = StructureJNI.TAG_ID3_get_id(pointer);
		return javaResult;
	}
	public void setId(String id)
	{
		if(pointer == 0) throw new NullPointerException();
		if((id != null) && (id.length() > 3)) {
			throw new IndexOutOfBoundsException();
		}
		StructureJNI.TAG_ID3_set_id(pointer, id == null ? null : id.getBytes());
	}

	/**
	 * 
	 */
	public String getTitle()
	{
		if(pointer == 0) throw new NullPointerException();
		String javaResult = StructureJNI.TAG_ID3_get_title(pointer);
		return javaResult;
	}
	public void setTitle(String title)
	{
		if(pointer == 0) throw new NullPointerException();
		if((title != null) && (title.length() > 30)) {
			throw new IndexOutOfBoundsException();
		}
		StructureJNI.TAG_ID3_set_title(pointer, title == null ? null : title.getBytes());
	}

	/**
	 * 
	 */
	public String getArtist()
	{
		if(pointer == 0) throw new NullPointerException();
		String javaResult = StructureJNI.TAG_ID3_get_artist(pointer);
		return javaResult;
	}
	public void setArtist(String artist)
	{
		if(pointer == 0) throw new NullPointerException();
		if((artist != null) && (artist.length() > 30)) {
			throw new IndexOutOfBoundsException();
		}
		StructureJNI.TAG_ID3_set_artist(pointer, artist == null ? null : artist.getBytes());
	}

	/**
	 * 
	 */
	public String getAlbum()
	{
		if(pointer == 0) throw new NullPointerException();
		String javaResult = StructureJNI.TAG_ID3_get_album(pointer);
		return javaResult;
	}
	public void setAlbum(String album)
	{
		if(pointer == 0) throw new NullPointerException();
		if((album != null) && (album.length() > 30)) {
			throw new IndexOutOfBoundsException();
		}
		StructureJNI.TAG_ID3_set_album(pointer, album == null ? null : album.getBytes());
	}

	/**
	 * 
	 */
	public String getYear()
	{
		if(pointer == 0) throw new NullPointerException();
		String javaResult = StructureJNI.TAG_ID3_get_year(pointer);
		return javaResult;
	}
	public void setYear(String year)
	{
		if(pointer == 0) throw new NullPointerException();
		if((year != null) && (year.length() > 4)) {
			throw new IndexOutOfBoundsException();
		}
		StructureJNI.TAG_ID3_set_year(pointer, year == null ? null : year.getBytes());
	}

	/**
	 * 
	 */
	public String getComment()
	{
		if(pointer == 0) throw new NullPointerException();
		String javaResult = StructureJNI.TAG_ID3_get_comment(pointer);
		return javaResult;
	}
	public void setComment(String comment)
	{
		if(pointer == 0) throw new NullPointerException();
		if((comment != null) && (comment.length() > 30)) {
			throw new IndexOutOfBoundsException();
		}
		StructureJNI.TAG_ID3_set_comment(pointer, comment == null ? null : comment.getBytes());
	}

	/**
	 * 
	 */
	public byte getGenre()
	{
		if(pointer == 0) throw new NullPointerException();
		byte javaResult = StructureJNI.TAG_ID3_get_genre(pointer);
		return javaResult;
	}
	public void setGenre(byte genre)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.TAG_ID3_set_genre(pointer, genre);
	}

}