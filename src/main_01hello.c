/*
 * main_01hello.c
 *
 *  Created on: 2019年3月5日
 *      Author: jet
 */


#include <gst/gst.h>

int main_01(int argc, char *argv[]) {
  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;

  /* Initialize GStreamer */
  gst_init (&argc, &argv);

  /* Build the pipeline */
  //pipeline = gst_parse_launch ("playbin uri=http://docs.gstreamer.com/media/sintel_trailer-480p.webm", NULL);
  pipeline = gst_parse_launch ("playbin uri=rtsp://admin:admin$2018@192.168.0.64:554/h264/ch0/main/av_stream", NULL);
  //pipeline = gst_parse_launch ("playbin uri=file:///home/nvidia/Videos/MOV.mp4", NULL);
  //pipeline = gst_parse_launch ("playbin uri=file:///home/alex/videosrc/MOV.mp4", NULL);

  /* Start playing */
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  /* Wait until error or EOS */
  bus = gst_element_get_bus (pipeline);
  msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  /* Free resources */
  if (msg != NULL)
    gst_message_unref (msg);
  gst_object_unref (bus);
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);
  return 0;
}

