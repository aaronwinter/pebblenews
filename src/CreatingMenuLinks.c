#include <pebble.h>
  
#define NUM_MENU_SECTIONS 1
#define NUM_FIRST_MENU_ITEMS 25

static ScrollLayer *scroll_layer;
static TextLayer *text_layer;
static InverterLayer *inverter_layer;

char buffer [500];

static const int vert_scroll_text_padding = 4;

char* title_array[25] = {"Canadian government begins invalidating passports of citizens who have left to join extremist groups",
                         "French Warplanes Kill 75 IS Militants Near Mosul",
                         "US will not commit to climate change aid for poor nations at UN summit. Rich countries pledged to find $100bn a year by 2020, but so far only Germany has made a significant contribution.",
                         "American jailed in North Korea invited arrest deliberately, state media says: An American sentenced to six years’ hard labour in North Korea pretended to have secret US information and was deliberately arrested in a bid to become famous and meet the imprisoned US missionary Kenneth Bae",
                         "Ebola Patients Buying Survivors' Blood from Black Market, WHO Warns - It's said to have antibodies that can fight the deadly virus. Though the treatment is unproven. Illicit trade can lead to spread of other infections, including HIV. ",
                         "Kim Dotcom's Internet-Mana party rejected by NZ voters, as John Key's National party is set to win an absolute majority ",
                         "Pro-Russian separatists' weapons factory blows up in Eastern Ukraine ",
                         "Goldman Sachs has admitted in court documents to having used small gifts, occasional travel and an internship to cement its ties with Libya's sovereign wealth fund under Moamer Kadhafi ",
                         "Gay sex could be punishable by 100 lashes of the cane in Indonesia's staunchly conservative Aceh province if parliament passes a draft law that critics say violates basic human rights. ",
                         "The Islamic State is upset with the French government's new name for them ",
                         "The Australian government will introduce tough new legislation in parliament next week to tackle terrorism in the aftermath of the biggest crackdown in the country's history. ",
                         "Father of 'Jihadi John' weeps as he admits he and Osama bin Laden plotted 1998 US embassy bombings that killed 224 people ",
                         "IS militants are 'gangsters' who hijack Islam, Anonymous says: The “hacktivist” group Anonymous has launched a social media campaign against Islamic State militants, telling FRANCE 24 that Operation Ice ISIS aims to 'protect those who are defenseless, both in the cyber world and the real world.' ",
                         "Photographer ‘horrified’ after claims Britain First used picture - 'Everything she stood for, everything she fought for, for herself, her family, her daughters and future of her country, everything has been desecrated by how Jacqui Lambie and Britain First have used this photograph.' ",
                         "'This is our land!': West Bank village Wadi Fukin fights largest Israeli land grab in decades ",
                         "French farmers torch tax office ",
                         "Security stepped up at Vatican over fears of terror attack ",
                         "ISIS releases 49 Turkish hostages in Iraq ",
                         "New Zealand elections 2014: with 96% of the votes counted, National Government stays in power ",
                         "New Zealand 2014 Election: Center-right National Party projected to have won a third term, increasing their seats in parliament from the previous election ",
                         "Turkey opens border to 45,000 Kurds fleeing Isis in Syria ",
                         "Israel and hamas to meet in 5 days to negotiate long term truce ",
                         "Russian Bombers Intercepted Near Canadian Airspace ",
                         "A large majority of the Catalan regional parliament has voted in favour of a law that legislators say will allow it to hold a non-binding vote on independence from Spain in November. ",
                         "Israeli Civil Administration plans to expel thousands of Bedouins from homes, concentrate them in inadequate settlement "};
  
char* link_array[25] = {"www.basnews.com",
                     "www.news.nationalpost.com",
                     "www.theguardian.com",
                     "www.cnn.com",
                     "www.theguardian.com",
                     "www.huffingtonpost.com",
                     "www.france24.com",
                     "www.aljazeera.com",
                     "www.euronews.com",
                     "www.bbc.com",
                     "www.theguardian.com",
                     "www.in.reuters.com",
                     "www.nzherald.co.nz",
                     "www.tvnz.co.nz",
                     "www.bangkokpost.com",
                     "www.ctvnews.ca",
                     "www.bbc.com",
                     "www.euronews.ca",
                     "www.impactlab.net",
                     "www.theguardian.com",
                     "www.dailymail.co.uk",
                     "www.washingtonpost.com",
                     "www.bigstory.ap.org",
                          "www.dw.de"};


char* comment_array[25] = {"536 comments",
                        "108 comments",
                        "148 comments", 
                        "243 comments",
                        "217 comments",
                        "1028 comments",
                        "59 comments",
                        "130 comments",
                        "57 comments",
                        "307 comments",
                        "28 comments",
                        "38 comments",
                        "52 comments",
                        "17 comments",
                        "10 comments",
                        "469 comments",
                        "11 comments",
                        "19 comments",
                        "2750 comments",
                        "16 comments",
                        "9 comments",
                        "28 comments",
                        "14 comments",
                        "21 comments",
                           "13 comments"};

static Window *window;
static Window *subWindow;

void subWindow_load(Window *subWindow) {

}

void subWindow_unload(Window *subWindow) {
    
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
  subWindow = window_create();
  WindowHandlers subhandlers = {
    .load = subWindow_load,
    .unload = subWindow_unload,
  };
  window_set_window_handlers(subWindow, subhandlers);
  
  Layer *window_layer = window_get_root_layer(subWindow);
  GRect bounds = layer_get_frame(window_layer);
  GRect max_text_bounds = GRect(0, 0, bounds.size.w, 2000);
  
  scroll_layer = scroll_layer_create(bounds);
  scroll_layer_set_click_config_onto_window(scroll_layer, subWindow);
  
  snprintf(buffer, 500, "%s\n\n%s\n%s", title_array[index], link_array[index], comment_array[index]);
  
  text_layer = text_layer_create(max_text_bounds);
  text_layer_set_text(text_layer, buffer);
  
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  GSize max_size = text_layer_get_content_size(text_layer);
  text_layer_set_size(text_layer, max_size);
  scroll_layer_set_content_size(scroll_layer, GSize(bounds.size.w, max_size.h + vert_scroll_text_padding));
  
  scroll_layer_add_child(scroll_layer, text_layer_get_layer(text_layer));
  
  

  layer_add_child(window_layer, scroll_layer_get_layer(scroll_layer));
  
  
  window_stack_push(subWindow, true);
  
}





// This initializes the menu upon window load
static void window_load(Window *window) {
  // We'll have to load the icon before we can use it
  // Although we already defined NUM_FIRST_MENU_ITEMS, you can define
  // an int as such to easily change the order of menu items later
  int num_a_items = 0;

  for (int i=0; i<25; i++) {
    // This is an example of how you'd set a simple menu item
    first_menu_items[num_a_items++] = (SimpleMenuItem){
      // You should give each menu item a title and callback
      .subtitle = title_array[i],
      .callback = menu_select_callback,
    };
  }

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