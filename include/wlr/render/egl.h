#ifndef WLR_EGL_H
#define WLR_EGL_H

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <stdbool.h>

struct wlr_egl {
	EGLDisplay display;
	EGLConfig config;
	EGLContext context;

	const char *egl_exts;
	const char *gl_exts;

	struct wl_display *wl_display;
};

// TODO: Allocate and return a wlr_egl
/**
 *  Initializes an egl context for the given platform and remote display.
 * Will attempt to load all possibly required api functions.
 */
bool wlr_egl_init(struct wlr_egl *egl, EGLenum platform, EGLint visual_id, void *display);

/**
 * Frees all related egl resources, makes the context not-current and
 * unbinds a bound wayland display.
 */
void wlr_egl_free(struct wlr_egl *egl);

/**
 * Binds the given display to the egl instance.
 * This will allow clients to create egl surfaces from wayland ones and render to it.
 */
bool wlr_egl_bind_display(struct wlr_egl *egl, struct wl_display *local_display);

/**
 * Refer to the eglQueryWaylandBufferWL extension function.
 */
bool wlr_egl_query_wl_drm_size(struct wlr_egl *egl, struct wl_resource *buf,
	int32_t *width, int32_t *height);

/**
 * Returns a surface for the given native window
 * The window must match the remote display the wlr_egl was created with.
 */
EGLSurface wlr_egl_create_surface(struct wlr_egl *egl, void *window);

/**
 * Returns a string for the last error ocurred with egl.
 */
const char *egl_error(void);

#endif
