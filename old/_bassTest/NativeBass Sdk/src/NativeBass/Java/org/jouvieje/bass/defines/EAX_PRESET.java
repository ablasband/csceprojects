/**
 * 						NativeBass Project
 *
 * Want to use BASS (www.un4seen.com) in the Java language ? NativeBass is made for you.
 * Copyright © 2007 Jérôme JOUVIE (Jouvieje)
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

package org.jouvieje.bass.defines;

import org.jouvieje.bass.enumerations.EAX_ENVIRONMENT;

/**
 * EAX presets, usage: BASS_SetEAXParameters(EAX_PRESET_xxx)
 */
public class EAX_PRESET
{
	/** */
	public final static EAX_PRESET EAX_PRESET_GENERIC         = new EAX_PRESET("EAX_PRESET_GENERIC",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_GENERIC, 0.5F, 1.493F, 0.5F);
	/** */
	public final static EAX_PRESET EAX_PRESET_PADDEDCELL      = new EAX_PRESET("EAX_PRESET_PADDEDCELL",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_PADDEDCELL, 0.25F, 0.1F, 0.0F);
	/** */
	public final static EAX_PRESET EAX_PRESET_ROOM            = new EAX_PRESET("EAX_PRESET_ROOM",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_ROOM, 0.417F, 0.4F, 0.666F);
	/** */
	public final static EAX_PRESET EAX_PRESET_BATHROOM        = new EAX_PRESET("EAX_PRESET_BATHROOM",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_BATHROOM, 0.653F, 1.499F, 0.166F);
	/** */
	public final static EAX_PRESET EAX_PRESET_LIVINGROOM      = new EAX_PRESET("EAX_PRESET_LIVINGROOM",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_LIVINGROOM, 0.208F, 0.478F, 0.0F);
	/** */
	public final static EAX_PRESET EAX_PRESET_STONEROOM       = new EAX_PRESET("EAX_PRESET_STONEROOM",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_STONEROOM, 0.5F, 2.309F, 0.888F);
	/** */
	public final static EAX_PRESET EAX_PRESET_AUDITORIUM      = new EAX_PRESET("EAX_PRESET_AUDITORIUM",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_AUDITORIUM, 0.403F, 4.279F, 0.5F);
	/** */
	public final static EAX_PRESET EAX_PRESET_CONCERTHALL     = new EAX_PRESET("EAX_PRESET_CONCERTHALL",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_CONCERTHALL, 0.5F, 3.961F, 0.5F);
	/** */
	public final static EAX_PRESET EAX_PRESET_CAVE            = new EAX_PRESET("EAX_PRESET_CAVE",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_CAVE, 0.5F, 2.886F, 1.304F);
	/** */
	public final static EAX_PRESET EAX_PRESET_ARENA           = new EAX_PRESET("EAX_PRESET_ARENA",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_ARENA, 0.361F, 7.284F, 0.332F);
	/** */
	public final static EAX_PRESET EAX_PRESET_HANGAR          = new EAX_PRESET("EAX_PRESET_HANGAR",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_HANGAR, 0.5F, 10.0F, 0.3F);
	/** */
	public final static EAX_PRESET EAX_PRESET_CARPETEDHALLWAY = new EAX_PRESET("EAX_PRESET_CARPETEDHALLWAY",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_CARPETEDHALLWAY, 0.153F, 0.259F, 2.0F);
	/** */
	public final static EAX_PRESET EAX_PRESET_HALLWAY         = new EAX_PRESET("EAX_PRESET_HALLWAY",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_HALLWAY, 0.361F, 1.493F, 0.0F);
	/** */
	public final static EAX_PRESET EAX_PRESET_STONECORRIDOR   = new EAX_PRESET("EAX_PRESET_STONECORRIDOR",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_STONECORRIDOR, 0.444F, 2.697F, 0.638F);
	/** */
	public final static EAX_PRESET EAX_PRESET_ALLEY           = new EAX_PRESET("EAX_PRESET_ALLEY",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_ALLEY, 0.25F, 1.752F, 0.776F);
	/** */
	public final static EAX_PRESET EAX_PRESET_FOREST          = new EAX_PRESET("EAX_PRESET_FOREST",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_FOREST, 0.111F, 3.145F, 0.472F);
	/** */
	public final static EAX_PRESET EAX_PRESET_CITY            = new EAX_PRESET("EAX_PRESET_CITY",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_CITY, 0.111F, 2.767F, 0.224F);
	/** */
	public final static EAX_PRESET EAX_PRESET_MOUNTAINS       = new EAX_PRESET("EAX_PRESET_MOUNTAINS",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_MOUNTAINS, 0.194F, 7.841F, 0.472F);
	/** */
	public final static EAX_PRESET EAX_PRESET_QUARRY          = new EAX_PRESET("EAX_PRESET_QUARRY",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_QUARRY, 1.0F, 1.499F, 0.5F);
	/** */
	public final static EAX_PRESET EAX_PRESET_PLAIN           = new EAX_PRESET("EAX_PRESET_PLAIN",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_PLAIN, 0.097F, 2.767F, 0.224F);
	/** */
	public final static EAX_PRESET EAX_PRESET_PARKINGLOT      = new EAX_PRESET("EAX_PRESET_PARKINGLOT",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_PARKINGLOT, 0.208F, 1.652F, 1.5F);
	/** */
	public final static EAX_PRESET EAX_PRESET_SEWERPIPE       = new EAX_PRESET("EAX_PRESET_SEWERPIPE",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_SEWERPIPE, 0.652F, 2.886F, 0.25F);
	/** */
	public final static EAX_PRESET EAX_PRESET_UNDERWATER      = new EAX_PRESET("EAX_PRESET_UNDERWATER",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_UNDERWATER, 1.0F, 1.499F, 0.0F);
	/** */
	public final static EAX_PRESET EAX_PRESET_DRUGGED         = new EAX_PRESET("EAX_PRESET_DRUGGED",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_DRUGGED, 0.875F, 8.392F, 1.388F);
	/** */
	public final static EAX_PRESET EAX_PRESET_DIZZY           = new EAX_PRESET("EAX_PRESET_DIZZY",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_DIZZY, 0.139F, 17.234F, 0.666F);
	/** */
	public final static EAX_PRESET EAX_PRESET_PSYCHOTIC       = new EAX_PRESET("EAX_PRESET_PSYCHOTIC",
			EAX_ENVIRONMENT.EAX_ENVIRONMENT_PSYCHOTIC, 0.486F, 7.563F, 0.806F);

	private final String name;
	private final EAX_ENVIRONMENT env;
	private final float volume;
	private final float decay;
	private final float damping;
	
	private EAX_PRESET(String name, EAX_ENVIRONMENT env, float volume, float decay, float damping)
	{
		this.name = name;
		this.env = env;
		this.volume = volume;
		this.decay = decay;
		this.damping = damping;
	}
	
	public boolean equals(Object object)
	{
		return this == object;
	}

	public String toString()
	{
		return name;
	}
	
	public EAX_ENVIRONMENT getEnv()
	{
		return env;
	}
	public float getVolume()
	{
		return volume;
	}
	public float getDecay()
	{
		return decay;
	}
	public float getDamping()
	{
		return damping;
	}
}