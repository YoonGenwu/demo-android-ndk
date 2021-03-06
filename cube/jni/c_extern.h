#ifndef _C_EXTERN_H
#define _C_EXTERN_H

#include <jni.h>
#include <errno.h>

#include <EGL/egl.h>
#include <GLES/gl.h>

#include <android/sensor.h>
#include <android/log.h>
#include <android_native_app_glue.h>

/**
 * Our saved state data.
 */
struct saved_state {
    float angle;
    int32_t x;
    int32_t y;
    int32_t dx;
    int32_t dy;
};

/**
 * Shared state for our app.
 */
struct engine {
    struct android_app* app;

    ASensorManager* sensorManager;
    const ASensor* accelerometerSensor;
    ASensorEventQueue* sensorEventQueue;

    int animating;
    EGLDisplay display;
    EGLSurface surface;
    EGLContext context;
    int32_t width;
    int32_t height;
    struct saved_state state;
};

int engine_init_display(struct engine* engine);
void engine_draw_frame(struct engine* engine);
void engine_term_display(struct engine* engine);
int32_t engine_handle_input(struct android_app* app, AInputEvent* event);
void engine_handle_cmd(struct android_app* app, int32_t cmd);

#endif /* _C_EXTERN_H */
