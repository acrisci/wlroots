lib_shared = static_library('shared',
    ['shared.c', 'cat.c'],
    dependencies: dep_wlr)

executable('simple', 'simple.c', dependencies: dep_wlr, link_with: lib_shared)
executable('rotation', 'rotation.c', dependencies: dep_wlr, link_with: lib_shared)
executable('pointer', 'pointer.c', dependencies: dep_wlr, link_with: lib_shared)
executable('touch', 'touch.c', dependencies: dep_wlr, link_with: lib_shared)
executable('tablet', 'tablet.c', dependencies: dep_wlr, link_with: lib_shared)

compositor_src = [
    'compositor/main.c',
    'compositor/wl_compositor.c',
    'compositor/wl_shell.c',
    'compositor/xdg_shell.c',
	'compositor/protocols/xdg-shell.c',
]

wayland_scanner = find_program('wayland-scanner')
wayland_protocols_pkgdatadir = dep_wayland_proto.get_pkgconfig_variable('pkgdatadir')
xdg_shell_v6_xml = wayland_protocols_pkgdatadir + '/unstable/xdg-shell/xdg-shell-unstable-v6.xml'
protocols_dir = meson.current_source_dir() + '/compositor/protocols'

run_command(['mkdir', '-p', protocols_dir])

run_command([wayland_scanner, 'code', xdg_shell_v6_xml,
	protocols_dir + '/xdg-shell.c'])

run_command([wayland_scanner, 'server-header', xdg_shell_v6_xml,
	protocols_dir + '/xdg-shell.h'])

executable('compositor', compositor_src, dependencies: dep_wlr, link_with: lib_shared)
