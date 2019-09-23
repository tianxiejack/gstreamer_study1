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
	const gchar *nano_str;

	guint major, minor, micro, nano;

	gst_init (&argc, &argv);

	gst_version (&major, &minor, &micro, &nano);

	if (nano == 1)
		nano_str = "(CVS)";
	else if (nano == 2)
		nano_str = "(Prerelease)";
	else
		nano_str = " ";

	printf ("This program is linked against GStreamer %d.%d.%d %s\n",
			major, minor, micro, nano_str);



	printf ("This program is linked against GStreamer %d.%d.%d %s\n",
			GST_VERSION_MAJOR, GST_VERSION_MINOR, GST_VERSION_MICRO, nano_str);
	return 0;
}
