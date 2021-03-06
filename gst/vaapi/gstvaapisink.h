/*
 *  gstvaapisink.h - VA-API video sink
 *
 *  Copyright (C) 2010-2011 Splitted-Desktop Systems
 *  Copyright (C) 2011 Intel Corporation
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation; either version 2.1
 *  of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301 USA
*/

#ifndef GST_VAAPISINK_H
#define GST_VAAPISINK_H

#include <gst/video/gstvideosink.h>
#include <gst/vaapi/gstvaapidisplay.h>
#include <gst/vaapi/gstvaapiwindow.h>
#if USE_VAAPISINK_GLX
#include <gst/vaapi/gstvaapitexture.h>
#endif
#include <X11/Xlib.h>

G_BEGIN_DECLS

#define GST_TYPE_VAAPISINK \
    (gst_vaapisink_get_type())

#define GST_VAAPISINK(obj)                              \
    (G_TYPE_CHECK_INSTANCE_CAST((obj),                  \
                                GST_TYPE_VAAPISINK,     \
                                GstVaapiSink))

#define GST_VAAPISINK_CLASS(klass)                      \
    (G_TYPE_CHECK_CLASS_CAST((klass),                   \
                             GST_TYPE_VAAPISINK,        \
                             GstVaapiSinkClass))

#define GST_IS_VAAPISINK(obj) \
    (G_TYPE_CHECK_INSTANCE_TYPE((obj), GST_TYPE_VAAPISINK))

#define GST_IS_VAAPISINK_CLASS(klass) \
    (G_TYPE_CHECK_CLASS_TYPE((klass), GST_TYPE_VAAPISINK))

#define GST_VAAPISINK_GET_CLASS(obj)                    \
    (G_TYPE_INSTANCE_GET_CLASS((obj),                   \
                               GST_TYPE_VAAPISINK,      \
                               GstVaapiSinkClass))

typedef struct _GstVaapiSink                    GstVaapiSink;
typedef struct _GstVaapiSinkClass               GstVaapiSinkClass;

#if !USE_VAAPISINK_GLX
typedef struct _GstVaapiTexture                 GstVaapiTexture;
#endif

struct _GstVaapiSink {
    /*< private >*/
    GstVideoSink parent_instance;

    GstCaps            *caps;
    gchar              *display_name;
    GstVaapiDisplay    *display;
    GstVaapiWindow     *window;
    guint               window_width;
    guint               window_height;
    GstVaapiTexture    *texture;
    guint               video_width;
    guint               video_height;
    gint                video_par_n;
    gint                video_par_d;
    GstVaapiRectangle   display_rect;
    guint               foreign_window  : 1;
    guint               fullscreen      : 1;
    guint               synchronous     : 1;
    guint               use_glx         : 1;
    guint               use_reflection  : 1;
};

struct _GstVaapiSinkClass {
    /*< private >*/
    GstVideoSinkClass parent_class;
};

GType
gst_vaapisink_get_type(void);

G_END_DECLS

#endif /* GST_VAAPISINK_H */
