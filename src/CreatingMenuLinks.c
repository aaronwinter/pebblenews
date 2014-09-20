#include <pebble.h>

#define NUM_MENU_SECTIONS 1
#define NUM_FIRST_MENU_ITEMS 25


static Window *window;
static Window *subWindow;

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
  
  void subWindow_load(Window *subWindow)
{
  
  title_layer = init_text_layer(GRect(5, 5, 134, 100), GColorBlack, GColorClear, "RESOURCE_ID_GOTHIC_18", GTextAlignmentLeft);
  text_layer_set_text(title_layer, "China insists wealthy countries should improve emission targets if a global pact on climate change is to be reached next year. A much-anticipated UN summit will be held in Paris aiming to produce most ambitious deal yet in fight against global warming.");
  layer_add_child(window_get_root_layer(subWindow), text_layer_get_layer(title_layer));  
  
  link_layer = init_text_layer(GRect(5, 118, 134, 20), GColorBlack, GColorClear, "RESOURCE_ID_GOTHIC_9", GTextAlignmentLeft);
  text_layer_set_text(link_layer, "www.bbcnews.com/yoloswag/hashtag");
  layer_add_child(window_get_root_layer(subWindow), text_layer_get_layer(link_layer));  
  
  comments_layer = init_text_layer(GRect(5, 128, 134, 20), GColorBlack, GColorClear, "RESOURCE_ID_GOTHIC_18", GTextAlignmentLeft);
  text_layer_set_text(comments_layer, "1337 comments");
  layer_add_child(window_get_root_layer(subWindow), text_layer_get_layer(comments_layer));  

}

  void subWindow_unload(Window *subWindow){
    
  text_layer_destroy(title_layer);
  text_layer_destroy(link_layer);
  text_layer_destroy(comments_layer);
}

// This is a simple menu layer
static SimpleMenuLayer *simple_menu_layer;

// A simple menu layer can have multiple sections
static SimpleMenuSection menu_sections[NUM_MENU_SECTIONS];

// Each section is composed of a number of menu items
static SimpleMenuItem first_menu_items[NUM_FIRST_MENU_ITEMS];



// Menu items can optionally have icons

static bool special_flag = false;

static int hit_count = 0;

// You can capture when the user selects a menu icon with a menu item select callback
static void menu_select_callback(int index, void *ctx) {
  // Here we just change the subtitle to a literal string
 // first_menu_items[index].subtitle = "You've hit select here!";
  // Mark the layer to be update
 // layer_mark_dirty(simple_menu_layer_get_layer(simple_menu_layer));
	//window_set_window_handlers(window, (WindowHandlers) {
  //.load = subWindow_load,
  //.unload = subWindow_unload,
  //window_set_window_handlers(subWindow, handlers);
 
  //window_stack_push(subWindow, true);
  
  subWindow = window_create();
  WindowHandlers subhandlers = {
    .load = subWindow_load,
    .unload = subWindow_unload
  };
  window_set_window_handlers(subWindow, subhandlers);
 
  window_stack_push(subWindow, true);

	
}



// This initializes the menu upon window load
static void window_load(Window *window) {
  // We'll have to load the icon before we can use it
  // Although we already defined NUM_FIRST_MENU_ITEMS, you can define
  // an int as such to easily change the order of menu items later
  int num_a_items = 0;

  // This is an example of how you'd set a simple menu item
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .subtitle="French Warplanes Kill 75 IS Militants Near Mosul",
    .callback = menu_select_callback,
  };
  // The menu items appear in the order saved in the menu items array
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "2",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "3",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "4",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "5",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "6",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "7",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "8",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "9",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "10",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "11",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "12",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "13",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "14",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "15",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "16",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "17",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "18",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "19",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "20",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "21",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "22",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "23",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "24",
    .callback = menu_select_callback,
  };
  
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    // You should give each menu item a title and callback
    .title = "25",
    .callback = menu_select_callback,
  };

  

  // Bind the menu items to the corresponding menu sections
  menu_sections[0] = (SimpleMenuSection){
    .num_items = NUM_FIRST_MENU_ITEMS,
    .items = first_menu_items,
  };

  // Now we prepare to initialize the simple menu layer
  // We need the bounds to specify the simple menu layer's viewport size
  // In this case, it'll be the same as the window's
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  // Initialize the simple menu layer
  simple_menu_layer = simple_menu_layer_create(bounds, window, menu_sections, NUM_MENU_SECTIONS, NULL);

  // Add it to the window for display
  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

// Deinitialize resources on window unload that were initialized on window load
void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
}

int main(void) {
  window = window_create();

  // Setup the window handlers
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });

  window_stack_push(window, true);

  app_event_loop();

  window_destroy(window);
}