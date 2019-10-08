/*
 * main_test.cpp
 *
 *  Created on: 2019年9月23日
 *      Author: alex
 */

#include <gst/gst.h>
#include <stdio.h>

int main_test (int argc,char *argv[])
{


	GstElementFactory *factory;
	/* init GStreamer */
	gst_init (&argc, &argv);


	/* get factory */
	factory = gst_element_factory_find ("audiotestsrc");
	if (!factory) {
	g_print ("You don't have the 'audiotestsrc' element installed!\n");
	return -1;
	}
	/* display information */
	g_print ("The '%s' element is a member of the category %s.\n"
	"Description: %s\n",
	gst_plugin_feature_get_name (GST_PLUGIN_FEATURE (factory)),
	gst_element_factory_get_klass (factory),
	gst_element_factory_get_description (factory));


	return 0;
}
