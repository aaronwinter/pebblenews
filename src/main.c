#include <pebble.h>
 
Window* window;
TextLayer *title_layer, *link_layer, *comments_layer;

static TextLayer* init_text_layer(GRect location, GColor colour, GColor background, const char *res_id, GTextAlignment alignment)
{
  TextLayer *layer = text_layer_create(location);
  text_layer_set_text_color(layer, colour);
  text_layer_set_background_color(layer, background);
  text_layer_set_font(layer, fonts_get_system_font(res_id));
  text_layer_set_text_alignment(layer, alignment);
 
  return layer;
}

void window_load(Window *window)
{
  title_layer = init_text_layer(GRect(5, 10, 158, 124), GColorBlack, GColorClear, "RESOURCE_ID_GOTHIC_18", GTextAlignmentLeft);
  text_layer_set_text(title_layer, "$100B invested in wind or solar will now produce more energy than the same investment in oil");
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(title_layer));  
  
  link_layer = init_text_layer(GRect(0, 0, 0, 0), GColorBlack, GColorClear, "RESOURCE_ID_GOTHIC_18", GTextAlignmentLeft);
  text_layer_set_text(link_layer, "");
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(link_layer));  
  
  comments_layer = init_text_layer(GRect(0, 0, 0, 0), GColorBlack, GColorClear, "RESOURCE_ID_GOTHIC_18", GTextAlignmentLeft);
  text_layer_set_text(comments_layer, "");
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(comments_layer));  
  
}
 
void window_unload(Window *window)
{
  text_layer_destroy(title_layer);
  text_layer_destroy(link_layer);
  text_layer_destroy(comments_layer);
}
 
void init()
{
  window = window_create();
  WindowHandlers handlers = {
    .load = window_load,
    .unload = window_unload
  };
  window_set_window_handlers(window, handlers);
 
  window_stack_push(window, true);
}
 
void deinit()
{
  window_destroy(window);
}
 
int main(void)
{
  init();
  app_event_loop();
  deinit();
}