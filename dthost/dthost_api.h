#ifndef DTHOST_API_H
#define DTHOST_API_H

#include "dt_av.h"

#include <stdint.h>

#define AUDIO_EXTR_DATA_SIZE 4096
#define VIDEO_EXTR_DATA_SIZE 4096

typedef struct
{
    /*flag */
    int has_audio;
    int has_video;
    int has_sub;
    int sync_enable;

    /*audio */
    int audio_format;
    int audio_channel;
    int audio_samplerate;
    int audio_dst_channels;
    int audio_dst_samplerate;
    int audio_bitrate;
    int audio_sample_fmt;
    int audio_codec_id;
    int audio_block_align;
    int audio_num, audio_den;   //for stream pts calc
    int audio_extra_size;
    unsigned char audio_extra_data[AUDIO_EXTR_DATA_SIZE];
    int audio_filter;           //audio filter options
    int audio_output;           //audio output device select
    void *actx_priv;            //point to 

    /*video */
    int video_format;
    int video_dest_width;
    int video_dest_height;
    int video_src_width;
    int video_src_height;
    int video_dest_pixfmt;
    int video_src_pixfmt;
    int video_rate;
    int video_ratio;
    double video_fps;
    int video_num, video_den;   //for stream pts calc
    unsigned long long ratio64;
    int video_extra_size;
    unsigned char video_extra_data[VIDEO_EXTR_DATA_SIZE];
    int video_filter;
    int video_output;
    void *vctx_priv;

    /*sub */
    int sub_format;
    int sub_id;
    int sub_width;
    int sub_height;
} dthost_para_t;

typedef struct
{
    int abuf_level;
    int vbuf_level;
	int apkt_size;
    int vpkt_size;

    int adec_err_cnt;
    int vdec_err_cnt;

    int64_t cur_apts;
    int64_t cur_vpts;
    int64_t cur_systime;

} host_state_t;

class dthost
{
public:
	dthost(){};
	std::function<int (dthost_para_t *para)>init;
	std::function<int ()>start;
	std::function<int ()>pause;
	std::function<int ()>resume;
	std::function<int ()>stop;
	std::function<int (dt_av_frame_t * frame, int type)>read_frame;
	std::function<int (dt_av_frame_t * frame, int type)>write_frame;
	std::function<int64_t ()>get_apts;
	std::function<int (int64_t pts)>update_apts;
	std::function<int64_t ()>get_vpts;
	std::function<int (int64_t pts)>update_vpts;
	std::function<int64_t ()>get_systime;
	std::function<int (int64_t pts)>update_systime;
	std::function<int ()>get_avdiff;
	std::function<int ()>get_current_time;
	std::function<int (host_state_t * state)>get_state;
	std::function<int ()>get_out_closed;
};

struct dthost_context;

class module_host
{
public:	
	dthost *host_ext;
	struct dthost_context *hctx;
	module_host();
	int dthost_start ();
	int dthost_pause ();
	int dthost_resume ();
	int dthost_stop ();
	int dthost_init (dthost_para_t * para);
	int dthost_read_frame (dt_av_frame_t * frame, int type);
	int dthost_write_frame (dt_av_frame_t * frame, int type);
	int64_t dthost_get_apts ();
	int dthost_update_apts (int64_t apts);
	int64_t dthost_get_vpts ();
	int dthost_update_vpts (int64_t vpts);
	int64_t dthost_get_avdiff ();
	int64_t dthost_get_current_time ();
	int64_t dthost_get_systime ();
	int dthost_update_systime (int64_t systime);
	int dthost_get_state (host_state_t * state);
	int dthost_get_out_closed ();
};

dthost *open_host_module();

#endif
