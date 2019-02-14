/*
 * main.cpp
 *
 *  Created on: 2019年1月22日
 *      Author: jet
 */


#include <gst/gst.h>


int main(int argc, char *argv[])
{
#if 0

	   const gchar *nano_str;
	    guint major, minor, micro, nano;
	    gst_init (&argc, &argv);
	    gst_version (&major, &minor, &micro, &nano);

	    if (nano == 1)
	        nano_str = "(CVS)";
	    else if (nano == 2)
	        nano_str = "(Prerelease)";
	    else
	        nano_str = "";

	    printf ("This program is linked against GStreamer %d.%d.%d %s\n",
	          major, minor, micro, nano_str);
	    return 0;

#else

  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;

  /* Initialize GStreamer */
  gst_init (&argc, &argv);

  /* Build the pipeline */
  pipeline = gst_parse_launch ("playbin uri=http://docs.gstreamer.com/media/sintel_trailer-480p.webm", NULL);

  /* Start playing */
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  /* Wait until error or EOS */
  bus = gst_element_get_bus (pipeline);

  msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_EOS | GST_MESSAGE_ERROR );

  /* Free resources */
  if (msg != NULL)
    gst_message_unref (msg);
  gst_object_unref (bus);
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);
  return 0;

#endif
}

