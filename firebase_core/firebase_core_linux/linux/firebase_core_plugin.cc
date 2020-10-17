#include "include/firebase_core_linux/firebase_core_plugin.h"

#include <flutter_linux/flutter_linux.h>
#include <gtk/gtk.h>

const char kChannelName[] = "plugins.flutter.io/firebase_core";
const char kInitializeCoreMethod[] = "initializeCore";

struct _FlFirebaseCorePlugin
{
    GObject parent_instance;

    FlPluginRegistrar *registrar;

    // Connection to Flutter engine.
    FlMethodChannel *channel;
};

G_DEFINE_TYPE(FlFirebaseCorePlugin, fl_firebase_core_plugin, g_object_get_type())

static void method_call_cb(FlMethodChannel *channel, FlMethodCall *method_call,
                           gpointer user_data)
{
    FlFirebaseCorePlugin *self = FL_URL_LAUNCHER_PLUGIN(user_data);

    const gchar *method = fl_method_call_get_name(method_call);
    FlValue *args = fl_method_call_get_args(method_call);

    g_autoptr(FlMethodResponse) response = nullptr;
    if (strcmp(method, kInitializeCoreMethod) == 0)
    {
        g_autoptr(FlValue) result = fl_value_new_bool(TRUE);
        response = FL_METHOD_RESPONSE(fl_method_success_response_new(result));
    }
    else
        response = FL_METHOD_RESPONSE(fl_method_not_implemented_response_new());

    g_autoptr(GError) error = nullptr;
    if (!fl_method_call_respond(method_call, response, &error))
        g_warning("Failed to send method call response: %s", error->message);
}