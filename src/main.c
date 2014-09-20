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
  
  title_layer = init_text_layer(GRect(5, 5, 134, 100), GColorBlack, GColorClear, "RESOURCE_ID_GOTHIC_18", GTextAlignmentLeft);
  text_layer_set_text(title_layer, "China insists wealthy countries should improve emission targets if a global pact on climate change is to be reached next year. A much-anticipated UN summit will be held in Paris aiming to produce most ambitious deal yet in fight against global warming.");
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(title_layer));  
  
  link_layer = init_text_layer(GRect(5, 118, 134, 20), GColorBlack, GColorClear, "RESOURCE_ID_GOTHIC_9", GTextAlignmentLeft);
  text_layer_set_text(link_layer, "www.bbcnews.com/yoloswag/hashtag");
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(link_layer));  
  
  comments_layer = init_text_layer(GRect(5, 128, 134, 20), GColorBlack, GColorClear, "RESOURCE_ID_GOTHIC_18", GTextAlignmentLeft);
  text_layer_set_text(comments_layer, "1337 comments");
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