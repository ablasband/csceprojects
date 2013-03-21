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

class StructureJNI
{
	static
	{
		if(!Init.isLibrariesLoaded())
		{
			throw new RuntimeException("Libraries not loaded ! Use Init.loadLibraries() before using NativeBass.");
		}
	}

						/* HMUSIC */


						/* HSAMPLE */


						/* HCHANNEL */

	protected final static native int HCHANNEL_SIZEOF();
	protected final static native long HCHANNEL_newArray(int length);

						/* HSTREAM */


						/* HRECORD */


						/* HSYNC */


						/* HDSP */


						/* HFX */


						/* HPLUGIN */


						/* BASS_DEVICEINFO */

	protected final static native long BASS_DEVICEINFO_new();
	protected final static native void BASS_DEVICEINFO_delete(long pointer);
	protected final static native String BASS_DEVICEINFO_get_name(long pointer);
	protected final static native void BASS_DEVICEINFO_set_name(long pointer, byte[] name);
	protected final static native String BASS_DEVICEINFO_get_driver(long pointer);
	protected final static native void BASS_DEVICEINFO_set_driver(long pointer, byte[] driver);
	protected final static native int BASS_DEVICEINFO_get_flags(long pointer);
	protected final static native void BASS_DEVICEINFO_set_flags(long pointer, int flags);

						/* BASS_INFO */

	protected final static native long BASS_INFO_new();
	protected final static native void BASS_INFO_delete(long pointer);
	protected final static native int BASS_INFO_get_flags(long pointer);
	protected final static native void BASS_INFO_set_flags(long pointer, int flags);
	protected final static native int BASS_INFO_get_hwsize(long pointer);
	protected final static native void BASS_INFO_set_hwsize(long pointer, int hwsize);
	protected final static native int BASS_INFO_get_hwfree(long pointer);
	protected final static native void BASS_INFO_set_hwfree(long pointer, int hwfree);
	protected final static native int BASS_INFO_get_freesam(long pointer);
	protected final static native void BASS_INFO_set_freesam(long pointer, int freesam);
	protected final static native int BASS_INFO_get_free3d(long pointer);
	protected final static native void BASS_INFO_set_free3d(long pointer, int free3d);
	protected final static native int BASS_INFO_get_minrate(long pointer);
	protected final static native void BASS_INFO_set_minrate(long pointer, int minrate);
	protected final static native int BASS_INFO_get_maxrate(long pointer);
	protected final static native void BASS_INFO_set_maxrate(long pointer, int maxrate);
	protected final static native boolean BASS_INFO_get_eax(long pointer);
	protected final static native void BASS_INFO_set_eax(long pointer, boolean eax);
	protected final static native int BASS_INFO_get_minbuf(long pointer);
	protected final static native void BASS_INFO_set_minbuf(long pointer, int minbuf);
	protected final static native int BASS_INFO_get_dsver(long pointer);
	protected final static native void BASS_INFO_set_dsver(long pointer, int dsver);
	protected final static native int BASS_INFO_get_latency(long pointer);
	protected final static native void BASS_INFO_set_latency(long pointer, int latency);
	protected final static native int BASS_INFO_get_initflags(long pointer);
	protected final static native void BASS_INFO_set_initflags(long pointer, int initflags);
	protected final static native int BASS_INFO_get_speakers(long pointer);
	protected final static native void BASS_INFO_set_speakers(long pointer, int speakers);
	protected final static native int BASS_INFO_get_freq(long pointer);
	protected final static native void BASS_INFO_set_freq(long pointer, int freq);

						/* BASS_RECORDINFO */

	protected final static native long BASS_RECORDINFO_new();
	protected final static native void BASS_RECORDINFO_delete(long pointer);
	protected final static native int BASS_RECORDINFO_get_flags(long pointer);
	protected final static native void BASS_RECORDINFO_set_flags(long pointer, int flags);
	protected final static native int BASS_RECORDINFO_get_formats(long pointer);
	protected final static native void BASS_RECORDINFO_set_formats(long pointer, int formats);
	protected final static native int BASS_RECORDINFO_get_inputs(long pointer);
	protected final static native void BASS_RECORDINFO_set_inputs(long pointer, int inputs);
	protected final static native boolean BASS_RECORDINFO_get_singlein(long pointer);
	protected final static native void BASS_RECORDINFO_set_singlein(long pointer, boolean singlein);
	protected final static native int BASS_RECORDINFO_get_freq(long pointer);
	protected final static native void BASS_RECORDINFO_set_freq(long pointer, int freq);

						/* BASS_SAMPLE */

	protected final static native long BASS_SAMPLE_new();
	protected final static native void BASS_SAMPLE_delete(long pointer);
	protected final static native int BASS_SAMPLE_get_freq(long pointer);
	protected final static native void BASS_SAMPLE_set_freq(long pointer, int freq);
	protected final static native float BASS_SAMPLE_get_volume(long pointer);
	protected final static native void BASS_SAMPLE_set_volume(long pointer, float volume);
	protected final static native float BASS_SAMPLE_get_pan(long pointer);
	protected final static native void BASS_SAMPLE_set_pan(long pointer, float pan);
	protected final static native int BASS_SAMPLE_get_flags(long pointer);
	protected final static native void BASS_SAMPLE_set_flags(long pointer, int flags);
	protected final static native int BASS_SAMPLE_get_length(long pointer);
	protected final static native void BASS_SAMPLE_set_length(long pointer, int length);
	protected final static native int BASS_SAMPLE_get_max(long pointer);
	protected final static native void BASS_SAMPLE_set_max(long pointer, int max);
	protected final static native int BASS_SAMPLE_get_origres(long pointer);
	protected final static native void BASS_SAMPLE_set_origres(long pointer, int origres);
	protected final static native int BASS_SAMPLE_get_chans(long pointer);
	protected final static native void BASS_SAMPLE_set_chans(long pointer, int chans);
	protected final static native int BASS_SAMPLE_get_mingap(long pointer);
	protected final static native void BASS_SAMPLE_set_mingap(long pointer, int mingap);
	protected final static native int BASS_SAMPLE_get_mode3d(long pointer);
	protected final static native void BASS_SAMPLE_set_mode3d(long pointer, int mode3d);
	protected final static native float BASS_SAMPLE_get_mindist(long pointer);
	protected final static native void BASS_SAMPLE_set_mindist(long pointer, float mindist);
	protected final static native float BASS_SAMPLE_get_maxdist(long pointer);
	protected final static native void BASS_SAMPLE_set_maxdist(long pointer, float maxdist);
	protected final static native int BASS_SAMPLE_get_iangle(long pointer);
	protected final static native void BASS_SAMPLE_set_iangle(long pointer, int iangle);
	protected final static native int BASS_SAMPLE_get_oangle(long pointer);
	protected final static native void BASS_SAMPLE_set_oangle(long pointer, int oangle);
	protected final static native float BASS_SAMPLE_get_outvol(long pointer);
	protected final static native void BASS_SAMPLE_set_outvol(long pointer, float outvol);
	protected final static native int BASS_SAMPLE_get_vam(long pointer);
	protected final static native void BASS_SAMPLE_set_vam(long pointer, int vam);
	protected final static native int BASS_SAMPLE_get_priority(long pointer);
	protected final static native void BASS_SAMPLE_set_priority(long pointer, int priority);

						/* BASS_CHANNELINFO */

	protected final static native long BASS_CHANNELINFO_new();
	protected final static native void BASS_CHANNELINFO_delete(long pointer);
	protected final static native int BASS_CHANNELINFO_get_freq(long pointer);
	protected final static native void BASS_CHANNELINFO_set_freq(long pointer, int freq);
	protected final static native int BASS_CHANNELINFO_get_chans(long pointer);
	protected final static native void BASS_CHANNELINFO_set_chans(long pointer, int chans);
	protected final static native int BASS_CHANNELINFO_get_flags(long pointer);
	protected final static native void BASS_CHANNELINFO_set_flags(long pointer, int flags);
	protected final static native int BASS_CHANNELINFO_get_ctype(long pointer);
	protected final static native void BASS_CHANNELINFO_set_ctype(long pointer, int ctype);
	protected final static native int BASS_CHANNELINFO_get_origres(long pointer);
	protected final static native void BASS_CHANNELINFO_set_origres(long pointer, int origres);
	protected final static native long BASS_CHANNELINFO_get_plugin(long pointer);
	protected final static native void BASS_CHANNELINFO_set_plugin(long pointer, long plugin);
	protected final static native long BASS_CHANNELINFO_get_sample(long pointer);
	protected final static native void BASS_CHANNELINFO_set_sample(long pointer, long sample);
	protected final static native String BASS_CHANNELINFO_get_filename(long pointer);
	protected final static native void BASS_CHANNELINFO_set_filename(long pointer, byte[] filename);

						/* BASS_PLUGINFORM */

	protected final static native int BASS_PLUGINFORM_SIZEOF();
	protected final static native long BASS_PLUGINFORM_newArray(int length);
	protected final static native long BASS_PLUGINFORM_new();
	protected final static native void BASS_PLUGINFORM_delete(long pointer);
	protected final static native int BASS_PLUGINFORM_get_ctype(long pointer);
	protected final static native void BASS_PLUGINFORM_set_ctype(long pointer, int ctype);
	protected final static native String BASS_PLUGINFORM_get_name(long pointer);
	protected final static native void BASS_PLUGINFORM_set_name(long pointer, byte[] name);
	protected final static native String BASS_PLUGINFORM_get_exts(long pointer);
	protected final static native void BASS_PLUGINFORM_set_exts(long pointer, byte[] exts);

						/* BASS_PLUGININFO */

	protected final static native long BASS_PLUGININFO_new();
	protected final static native void BASS_PLUGININFO_delete(long pointer);
	protected final static native int BASS_PLUGININFO_get_version(long pointer);
	protected final static native void BASS_PLUGININFO_set_version(long pointer, int version);
	protected final static native int BASS_PLUGININFO_get_formatc(long pointer);
	protected final static native void BASS_PLUGININFO_set_formatc(long pointer, int formatc);
	protected final static native long BASS_PLUGININFO_get_formats(long pointer);
	protected final static native void BASS_PLUGININFO_set_formats(long pointer, long formats);

						/* BASS_3DVECTOR */

	protected final static native long BASS_3DVECTOR_new();
	protected final static native void BASS_3DVECTOR_delete(long pointer);
	protected final static native float BASS_3DVECTOR_get_x(long pointer);
	protected final static native void BASS_3DVECTOR_set_x(long pointer, float x);
	protected final static native float BASS_3DVECTOR_get_y(long pointer);
	protected final static native void BASS_3DVECTOR_set_y(long pointer, float y);
	protected final static native float BASS_3DVECTOR_get_z(long pointer);
	protected final static native void BASS_3DVECTOR_set_z(long pointer, float z);

	protected final static native long BASS_3DVECTOR_create(float x, float y, float z);
	protected final static native void BASS_3DVECTOR_set_xyz(long pointer, long vector);
	protected final static native void BASS_3DVECTOR_set_xyz(long pointer, float x, float y, float z);

						/* BASS_FILEPROCS */

	protected final static native long BASS_FILEPROCS_new();
	protected final static native void BASS_FILEPROCS_delete(long pointer);
	protected final static native void BASS_FILEPROCS_set_close(long pointer, boolean close);
	protected final static native void BASS_FILEPROCS_set_length(long pointer, boolean length);
	protected final static native void BASS_FILEPROCS_set_read(long pointer, boolean read);
	protected final static native void BASS_FILEPROCS_set_seek(long pointer, boolean seek);

						/* TAG_ID3 */

	protected final static native long TAG_ID3_new();
	protected final static native void TAG_ID3_delete(long pointer);
	protected final static native String TAG_ID3_get_id(long pointer);
	protected final static native void TAG_ID3_set_id(long pointer, byte[] id);
	protected final static native String TAG_ID3_get_title(long pointer);
	protected final static native void TAG_ID3_set_title(long pointer, byte[] title);
	protected final static native String TAG_ID3_get_artist(long pointer);
	protected final static native void TAG_ID3_set_artist(long pointer, byte[] artist);
	protected final static native String TAG_ID3_get_album(long pointer);
	protected final static native void TAG_ID3_set_album(long pointer, byte[] album);
	protected final static native String TAG_ID3_get_year(long pointer);
	protected final static native void TAG_ID3_set_year(long pointer, byte[] year);
	protected final static native String TAG_ID3_get_comment(long pointer);
	protected final static native void TAG_ID3_set_comment(long pointer, byte[] comment);
	protected final static native byte TAG_ID3_get_genre(long pointer);
	protected final static native void TAG_ID3_set_genre(long pointer, byte genre);

						/* TAG_BEXT */

	protected final static native long TAG_BEXT_new();
	protected final static native void TAG_BEXT_delete(long pointer);
	protected final static native String TAG_BEXT_get_Description(long pointer);
	protected final static native void TAG_BEXT_set_Description(long pointer, byte[] Description);
	protected final static native String TAG_BEXT_get_Originator(long pointer);
	protected final static native void TAG_BEXT_set_Originator(long pointer, byte[] Originator);
	protected final static native String TAG_BEXT_get_OriginatorReference(long pointer);
	protected final static native void TAG_BEXT_set_OriginatorReference(long pointer, byte[] OriginatorReference);
	protected final static native String TAG_BEXT_get_OriginationDate(long pointer);
	protected final static native void TAG_BEXT_set_OriginationDate(long pointer, byte[] OriginationDate);
	protected final static native String TAG_BEXT_get_OriginationTime(long pointer);
	protected final static native void TAG_BEXT_set_OriginationTime(long pointer, byte[] OriginationTime);
	protected final static native long TAG_BEXT_get_TimeReference(long pointer);
	protected final static native void TAG_BEXT_set_TimeReference(long pointer, long TimeReference);
	protected final static native short TAG_BEXT_get_Version(long pointer);
	protected final static native void TAG_BEXT_set_Version(long pointer, short Version);
	protected final static native ByteBuffer TAG_BEXT_get_UMID(long pointer);
	protected final static native void TAG_BEXT_set_UMID(long pointer, byte[] UMID);
	protected final static native ByteBuffer TAG_BEXT_get_Reserved(long pointer);
	protected final static native void TAG_BEXT_set_Reserved(long pointer, byte[] Reserved);

						/* BASS_DX8_CHORUS */

	protected final static native long BASS_DX8_CHORUS_new();
	protected final static native void BASS_DX8_CHORUS_delete(long pointer);
	protected final static native float BASS_DX8_CHORUS_get_fWetDryMix(long pointer);
	protected final static native void BASS_DX8_CHORUS_set_fWetDryMix(long pointer, float fWetDryMix);
	protected final static native float BASS_DX8_CHORUS_get_fDepth(long pointer);
	protected final static native void BASS_DX8_CHORUS_set_fDepth(long pointer, float fDepth);
	protected final static native float BASS_DX8_CHORUS_get_fFeedback(long pointer);
	protected final static native void BASS_DX8_CHORUS_set_fFeedback(long pointer, float fFeedback);
	protected final static native float BASS_DX8_CHORUS_get_fFrequency(long pointer);
	protected final static native void BASS_DX8_CHORUS_set_fFrequency(long pointer, float fFrequency);
	protected final static native int BASS_DX8_CHORUS_get_lWaveform(long pointer);
	protected final static native void BASS_DX8_CHORUS_set_lWaveform(long pointer, int lWaveform);
	protected final static native float BASS_DX8_CHORUS_get_fDelay(long pointer);
	protected final static native void BASS_DX8_CHORUS_set_fDelay(long pointer, float fDelay);
	protected final static native int BASS_DX8_CHORUS_get_lPhase(long pointer);
	protected final static native void BASS_DX8_CHORUS_set_lPhase(long pointer, int lPhase);

						/* BASS_DX8_COMPRESSOR */

	protected final static native long BASS_DX8_COMPRESSOR_new();
	protected final static native void BASS_DX8_COMPRESSOR_delete(long pointer);
	protected final static native float BASS_DX8_COMPRESSOR_get_fGain(long pointer);
	protected final static native void BASS_DX8_COMPRESSOR_set_fGain(long pointer, float fGain);
	protected final static native float BASS_DX8_COMPRESSOR_get_fAttack(long pointer);
	protected final static native void BASS_DX8_COMPRESSOR_set_fAttack(long pointer, float fAttack);
	protected final static native float BASS_DX8_COMPRESSOR_get_fRelease(long pointer);
	protected final static native void BASS_DX8_COMPRESSOR_set_fRelease(long pointer, float fRelease);
	protected final static native float BASS_DX8_COMPRESSOR_get_fThreshold(long pointer);
	protected final static native void BASS_DX8_COMPRESSOR_set_fThreshold(long pointer, float fThreshold);
	protected final static native float BASS_DX8_COMPRESSOR_get_fRatio(long pointer);
	protected final static native void BASS_DX8_COMPRESSOR_set_fRatio(long pointer, float fRatio);
	protected final static native float BASS_DX8_COMPRESSOR_get_fPredelay(long pointer);
	protected final static native void BASS_DX8_COMPRESSOR_set_fPredelay(long pointer, float fPredelay);

						/* BASS_DX8_DISTORTION */

	protected final static native long BASS_DX8_DISTORTION_new();
	protected final static native void BASS_DX8_DISTORTION_delete(long pointer);
	protected final static native float BASS_DX8_DISTORTION_get_fGain(long pointer);
	protected final static native void BASS_DX8_DISTORTION_set_fGain(long pointer, float fGain);
	protected final static native float BASS_DX8_DISTORTION_get_fEdge(long pointer);
	protected final static native void BASS_DX8_DISTORTION_set_fEdge(long pointer, float fEdge);
	protected final static native float BASS_DX8_DISTORTION_get_fPostEQCenterFrequency(long pointer);
	protected final static native void BASS_DX8_DISTORTION_set_fPostEQCenterFrequency(long pointer, float fPostEQCenterFrequency);
	protected final static native float BASS_DX8_DISTORTION_get_fPostEQBandwidth(long pointer);
	protected final static native void BASS_DX8_DISTORTION_set_fPostEQBandwidth(long pointer, float fPostEQBandwidth);
	protected final static native float BASS_DX8_DISTORTION_get_fPreLowpassCutoff(long pointer);
	protected final static native void BASS_DX8_DISTORTION_set_fPreLowpassCutoff(long pointer, float fPreLowpassCutoff);

						/* BASS_DX8_ECHO */

	protected final static native long BASS_DX8_ECHO_new();
	protected final static native void BASS_DX8_ECHO_delete(long pointer);
	protected final static native float BASS_DX8_ECHO_get_fWetDryMix(long pointer);
	protected final static native void BASS_DX8_ECHO_set_fWetDryMix(long pointer, float fWetDryMix);
	protected final static native float BASS_DX8_ECHO_get_fFeedback(long pointer);
	protected final static native void BASS_DX8_ECHO_set_fFeedback(long pointer, float fFeedback);
	protected final static native float BASS_DX8_ECHO_get_fLeftDelay(long pointer);
	protected final static native void BASS_DX8_ECHO_set_fLeftDelay(long pointer, float fLeftDelay);
	protected final static native float BASS_DX8_ECHO_get_fRightDelay(long pointer);
	protected final static native void BASS_DX8_ECHO_set_fRightDelay(long pointer, float fRightDelay);
	protected final static native boolean BASS_DX8_ECHO_get_lPanDelay(long pointer);
	protected final static native void BASS_DX8_ECHO_set_lPanDelay(long pointer, boolean lPanDelay);

						/* BASS_DX8_FLANGER */

	protected final static native long BASS_DX8_FLANGER_new();
	protected final static native void BASS_DX8_FLANGER_delete(long pointer);
	protected final static native float BASS_DX8_FLANGER_get_fWetDryMix(long pointer);
	protected final static native void BASS_DX8_FLANGER_set_fWetDryMix(long pointer, float fWetDryMix);
	protected final static native float BASS_DX8_FLANGER_get_fDepth(long pointer);
	protected final static native void BASS_DX8_FLANGER_set_fDepth(long pointer, float fDepth);
	protected final static native float BASS_DX8_FLANGER_get_fFeedback(long pointer);
	protected final static native void BASS_DX8_FLANGER_set_fFeedback(long pointer, float fFeedback);
	protected final static native float BASS_DX8_FLANGER_get_fFrequency(long pointer);
	protected final static native void BASS_DX8_FLANGER_set_fFrequency(long pointer, float fFrequency);
	protected final static native int BASS_DX8_FLANGER_get_lWaveform(long pointer);
	protected final static native void BASS_DX8_FLANGER_set_lWaveform(long pointer, int lWaveform);
	protected final static native float BASS_DX8_FLANGER_get_fDelay(long pointer);
	protected final static native void BASS_DX8_FLANGER_set_fDelay(long pointer, float fDelay);
	protected final static native int BASS_DX8_FLANGER_get_lPhase(long pointer);
	protected final static native void BASS_DX8_FLANGER_set_lPhase(long pointer, int lPhase);

						/* BASS_DX8_GARGLE */

	protected final static native long BASS_DX8_GARGLE_new();
	protected final static native void BASS_DX8_GARGLE_delete(long pointer);
	protected final static native int BASS_DX8_GARGLE_get_dwRateHz(long pointer);
	protected final static native void BASS_DX8_GARGLE_set_dwRateHz(long pointer, int dwRateHz);
	protected final static native int BASS_DX8_GARGLE_get_dwWaveShape(long pointer);
	protected final static native void BASS_DX8_GARGLE_set_dwWaveShape(long pointer, int dwWaveShape);

						/* BASS_DX8_I3DL2REVERB */

	protected final static native long BASS_DX8_I3DL2REVERB_new();
	protected final static native void BASS_DX8_I3DL2REVERB_delete(long pointer);
	protected final static native int BASS_DX8_I3DL2REVERB_get_lRoom(long pointer);
	protected final static native void BASS_DX8_I3DL2REVERB_set_lRoom(long pointer, int lRoom);
	protected final static native int BASS_DX8_I3DL2REVERB_get_lRoomHF(long pointer);
	protected final static native void BASS_DX8_I3DL2REVERB_set_lRoomHF(long pointer, int lRoomHF);
	protected final static native float BASS_DX8_I3DL2REVERB_get_flRoomRolloffFactor(long pointer);
	protected final static native void BASS_DX8_I3DL2REVERB_set_flRoomRolloffFactor(long pointer, float flRoomRolloffFactor);
	protected final static native float BASS_DX8_I3DL2REVERB_get_flDecayTime(long pointer);
	protected final static native void BASS_DX8_I3DL2REVERB_set_flDecayTime(long pointer, float flDecayTime);
	protected final static native float BASS_DX8_I3DL2REVERB_get_flDecayHFRatio(long pointer);
	protected final static native void BASS_DX8_I3DL2REVERB_set_flDecayHFRatio(long pointer, float flDecayHFRatio);
	protected final static native int BASS_DX8_I3DL2REVERB_get_lReflections(long pointer);
	protected final static native void BASS_DX8_I3DL2REVERB_set_lReflections(long pointer, int lReflections);
	protected final static native float BASS_DX8_I3DL2REVERB_get_flReflectionsDelay(long pointer);
	protected final static native void BASS_DX8_I3DL2REVERB_set_flReflectionsDelay(long pointer, float flReflectionsDelay);
	protected final static native int BASS_DX8_I3DL2REVERB_get_lReverb(long pointer);
	protected final static native void BASS_DX8_I3DL2REVERB_set_lReverb(long pointer, int lReverb);
	protected final static native float BASS_DX8_I3DL2REVERB_get_flReverbDelay(long pointer);
	protected final static native void BASS_DX8_I3DL2REVERB_set_flReverbDelay(long pointer, float flReverbDelay);
	protected final static native float BASS_DX8_I3DL2REVERB_get_flDiffusion(long pointer);
	protected final static native void BASS_DX8_I3DL2REVERB_set_flDiffusion(long pointer, float flDiffusion);
	protected final static native float BASS_DX8_I3DL2REVERB_get_flDensity(long pointer);
	protected final static native void BASS_DX8_I3DL2REVERB_set_flDensity(long pointer, float flDensity);
	protected final static native float BASS_DX8_I3DL2REVERB_get_flHFReference(long pointer);
	protected final static native void BASS_DX8_I3DL2REVERB_set_flHFReference(long pointer, float flHFReference);

						/* BASS_DX8_PARAMEQ */

	protected final static native long BASS_DX8_PARAMEQ_new();
	protected final static native void BASS_DX8_PARAMEQ_delete(long pointer);
	protected final static native float BASS_DX8_PARAMEQ_get_fCenter(long pointer);
	protected final static native void BASS_DX8_PARAMEQ_set_fCenter(long pointer, float fCenter);
	protected final static native float BASS_DX8_PARAMEQ_get_fBandwidth(long pointer);
	protected final static native void BASS_DX8_PARAMEQ_set_fBandwidth(long pointer, float fBandwidth);
	protected final static native float BASS_DX8_PARAMEQ_get_fGain(long pointer);
	protected final static native void BASS_DX8_PARAMEQ_set_fGain(long pointer, float fGain);

						/* BASS_DX8_REVERB */

	protected final static native long BASS_DX8_REVERB_new();
	protected final static native void BASS_DX8_REVERB_delete(long pointer);
	protected final static native float BASS_DX8_REVERB_get_fInGain(long pointer);
	protected final static native void BASS_DX8_REVERB_set_fInGain(long pointer, float fInGain);
	protected final static native float BASS_DX8_REVERB_get_fReverbMix(long pointer);
	protected final static native void BASS_DX8_REVERB_set_fReverbMix(long pointer, float fReverbMix);
	protected final static native float BASS_DX8_REVERB_get_fReverbTime(long pointer);
	protected final static native void BASS_DX8_REVERB_set_fReverbTime(long pointer, float fReverbTime);
	protected final static native float BASS_DX8_REVERB_get_fHighFreqRTRatio(long pointer);
	protected final static native void BASS_DX8_REVERB_set_fHighFreqRTRatio(long pointer, float fHighFreqRTRatio);

}