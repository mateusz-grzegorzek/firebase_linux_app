#ifndef PACKAGES_FIREBASE_CORE_FIREBASE_CORE_LINUX_LINUX_INCLUDE_FIREBASE_CORE_FIREBASE_CORE_PLUGIN_H_
#define PACKAGES_FIREBASE_CORE_FIREBASE_CORE_LINUX_LINUX_INCLUDE_FIREBASE_CORE_FIREBASE_CORE_PLUGIN_H_

// A plugin to launch URLs.

#include <flutter_linux/flutter_linux.h>

G_BEGIN_DECLS

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __attribute__((visibility("default")))
#else
#define FLUTTER_PLUGIN_EXPORT
#endif

G_DECLARE_FINAL_TYPE(FlFirebaseCorePlugin, fl_firebase_core_plugin, FL,
                     FIREBASE_CORE_PLUGIN, GObject)

FLUTTER_PLUGIN_EXPORT FlFirebaseCorePlugin *fl_firebase_core_plugin_new(
    FlPluginRegistrar *registrar);

FLUTTER_PLUGIN_EXPORT void firebase_core_plugin_register_with_registrar(
    FlPluginRegistrar *registrar);

G_END_DECLS

#endif // PACKAGES_FIREBASE_CORE_FIREBASE_CORE_LINUX_LINUX_INCLUDE_FIREBASE_CORE_FIREBASE_CORE_PLUGIN_H_