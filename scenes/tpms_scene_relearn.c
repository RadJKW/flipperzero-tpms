#include "../tpms_app_i.h"

enum TPMSRelearnSetting {
    TPMSRelearnSettingOff,
    TPMSRelearnSettingOn,
    TPMSRelearnSettingNum,
};

static const char* const relearn_setting_text[TPMSRelearnSettingNum] = {
    "OFF",
    "ON",
};

static const char* const relearn_pattern_text[] = {
    "Continuous",
    "Burst 100/100",
    "Burst 250/250",
    "Burst 500/100",
    "Burst 100/500",
};

static const char* const relearn_runtime_text[] = {
    "Toggle",
    "3s",
    "5s",
    "10s",
};

static const char* const relearn_duty_text[] = {
    "33%",
    "50%",
    "66%",
};

static void tpms_scene_relearn_setting_callback(VariableItem* item) {
    TPMSApp* app = variable_item_get_context(item);
    uint8_t index = variable_item_get_current_value_index(item);
    app->relearn = (index == TPMSRelearnSettingOn) ? TPMSRelearnOn : TPMSRelearnOff;
    variable_item_set_current_value_text(item, relearn_setting_text[index]);
}

static void tpms_scene_relearn_pattern_callback(VariableItem* item) {
    TPMSApp* app = variable_item_get_context(item);
    uint8_t index = variable_item_get_current_value_index(item);
    app->relearn_pattern = index;
    variable_item_set_current_value_text(item, relearn_pattern_text[index]);
}

static void tpms_scene_relearn_runtime_callback(VariableItem* item) {
    TPMSApp* app = variable_item_get_context(item);
    uint8_t index = variable_item_get_current_value_index(item);
    app->relearn_runtime = index;
    variable_item_set_current_value_text(item, relearn_runtime_text[index]);
}

static void tpms_scene_relearn_duty_callback(VariableItem* item) {
    TPMSApp* app = variable_item_get_context(item);
    uint8_t index = variable_item_get_current_value_index(item);
    app->relearn_duty = index;
    variable_item_set_current_value_text(item, relearn_duty_text[index]);
}

void tpms_scene_relearn_config_on_enter(void* context) {
    TPMSApp* app = context;
    VariableItemList* var_item_list = app->variable_item_list;
    VariableItem* item;

    item = variable_item_list_add(
        var_item_list,
        "Relearn 125kHz",
        TPMSRelearnSettingNum,
        tpms_scene_relearn_setting_callback,
        app);
    variable_item_set_current_value_index(item, app->relearn);
    variable_item_set_current_value_text(item, relearn_setting_text[app->relearn]);

    item = variable_item_list_add(
        var_item_list,
        "Pattern",
        COUNT_OF(relearn_pattern_text),
        tpms_scene_relearn_pattern_callback,
        app);
    variable_item_set_current_value_index(item, app->relearn_pattern);
    variable_item_set_current_value_text(item, relearn_pattern_text[app->relearn_pattern]);

    item = variable_item_list_add(
        var_item_list,
        "Runtime",
        COUNT_OF(relearn_runtime_text),
        tpms_scene_relearn_runtime_callback,
        app);
    variable_item_set_current_value_index(item, app->relearn_runtime);
    variable_item_set_current_value_text(item, relearn_runtime_text[app->relearn_runtime]);

    item = variable_item_list_add(
        var_item_list, "Duty", COUNT_OF(relearn_duty_text), tpms_scene_relearn_duty_callback, app);
    variable_item_set_current_value_index(item, app->relearn_duty);
    variable_item_set_current_value_text(item, relearn_duty_text[app->relearn_duty]);

    view_dispatcher_switch_to_view(app->view_dispatcher, TPMSViewVariableItemList);
}

bool tpms_scene_relearn_config_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void tpms_scene_relearn_config_on_exit(void* context) {
    TPMSApp* app = context;
    variable_item_list_set_selected_item(app->variable_item_list, 0);
    variable_item_list_reset(app->variable_item_list);
}
