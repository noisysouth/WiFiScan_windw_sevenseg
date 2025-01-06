// ---------------------------- Define windows + controls. --------------------------
// *** background frame ***
struct windw_s wnd_frame;

// *** wifi networks screen ***
//struct cap_windw_s cwnd_main;
//struct cap_twindw_s ctwnd_main;
//struct button_s btn_ok;
//struct edit_s edit_text;
//struct button_s btn_up;
//struct button_s btn_opt1;
//struct button_s btn_opt2;
//struct button_s btn_opt3;
//struct button_s btn_down;
struct list_s lst_nets;

struct tab_ctrl_s tab_ctrl_frame = 
      { ctrl_windw, &wnd_frame, };

struct tab_ctrl_s tab_ctrl_nets = 
      { ctrl_list, &lst_nets, };

struct tab_ctrl_s tab_ctrl_none = 
      { ctrl_type_none,  NULL, };

struct tab_ctrl_s *ctrls_wifi[] =
  {
    &tab_ctrl_frame,
    &tab_ctrl_nets,
    &tab_ctrl_none,
  };

struct ctrl_screen_s wifi_screen = {
//  {
//    { ctrl_edit,   &edit_text, },
//    { ctrl_button, &btn_up, },
//    { ctrl_button, &btn_opt1, },
//    { ctrl_list, &lst_nets, },
    //&tab_ctrl_nets,
//    { ctrl_button, &btn_down, },
//    { ctrl_type_none,  NULL, },
//    &tab_ctrl_none,
//  },
  ctrls_wifi,
  1, // focus_idx: ctrl_nets
};


// *** wifi password screen ***
struct windw_s wnd_plain;
struct label_s lbl_instr;
struct label_s lbl_net;
char wifi_net_str[LABEL_MAX_TEXT];
struct edit_s edit_pass;
struct button_s btn_ok;
struct button_s btn_back;

struct tab_ctrl_s tab_ctrl_plain = 
      { ctrl_windw, &wnd_plain, };

struct tab_ctrl_s tab_ctrl_instr = 
      { ctrl_label, &lbl_instr, };

struct tab_ctrl_s tab_ctrl_net = 
      { ctrl_label, &lbl_net, };

struct tab_ctrl_s tab_ctrl_pass = 
      { ctrl_edit, &edit_pass, };

struct tab_ctrl_s tab_ctrl_ok = 
      { ctrl_button, &btn_ok, };

struct tab_ctrl_s tab_ctrl_back = 
      { ctrl_button, &btn_back, };

struct tab_ctrl_s *ctrls_pass[] =
  {
    &tab_ctrl_plain,
    &tab_ctrl_instr,
    &tab_ctrl_net,
    &tab_ctrl_pass,
    &tab_ctrl_ok,
    &tab_ctrl_back,
    &tab_ctrl_none,
  };
  
struct ctrl_screen_s pass_screen = {
  ctrls_pass,
  3, // focus_idx: ctrl_pass
};

// *** main app screen ***
//struct cap_twindw_s ctwnd_main;
struct label_s lbl_clock;
struct check_box_s cb_lastcolon;
struct button_s btn_ip;
struct label_s lbl_utc;
struct up_down_s updn_tzone;
struct check_box_s cb_daylight;
struct label_s lbl_brightness;
struct up_down_s updn_bright;

//struct tab_ctrl_s tab_ctrl_main = 
//      { ctrl_cap_twindw, &ctwnd_main, };

struct tab_ctrl_s tab_ctrl_clock = 
      { ctrl_label, &lbl_clock, };

struct tab_ctrl_s tab_ctrl_lastcolon = 
      { ctrl_check_box, &cb_lastcolon, };

struct tab_ctrl_s tab_ctrl_ip = 
      { ctrl_button, &btn_ip, };

struct tab_ctrl_s tab_ctrl_utc = 
      { ctrl_label, &lbl_utc, };

struct tab_ctrl_s tab_ctrl_tzone = 
      { ctrl_up_down, &updn_tzone, };

struct tab_ctrl_s tab_ctrl_daylight = 
      { ctrl_check_box, &cb_daylight, };

struct tab_ctrl_s tab_ctrl_brightness = 
      { ctrl_label, &lbl_brightness, };

struct tab_ctrl_s tab_ctrl_bright = 
      { ctrl_up_down, &updn_bright, };

struct tab_ctrl_s *ctrls_app[] =
  {
    //&tab_ctrl_main,
    &tab_ctrl_plain,
    &tab_ctrl_clock,
    &tab_ctrl_lastcolon,
    &tab_ctrl_ip,
    &tab_ctrl_utc,
    &tab_ctrl_tzone,
    &tab_ctrl_daylight,
    &tab_ctrl_brightness,
    &tab_ctrl_bright,
    &tab_ctrl_none, // end of list
  };
  
struct ctrl_screen_s app_screen = {
  ctrls_app,
  1, // focus_idx: ctrl_ip
};

// *** initial screen at start ***
//struct ctrl_screen_s *cur_screen = &wifi_screen;
//struct ctrl_screen_s *cur_screen = &pass_screen;
struct ctrl_screen_s *cur_screen = &app_screen;

// ---------------------------- Set up screen controls -----------------------------------
void setup_app_screens(void) {
  // WiFi screen - setup elements
  SetupWindow (&wnd_frame, /*x0*/0, /*y0*/0, tft.width()-1, tft.height()-1, /*border*/1, /*buffered*/0);
  ////DrawWindow (&wnd_main);
  ////SetupCapWindow (&cwnd_main, /*x0*/0, /*y0*/0, tft.width()-1, tft.height()-1, /*border*/1, /*buffered*/0, "MP3 Jukebox");
  ////DrawCapWindow (&cwnd_main);
  ////SetupCapTWindow (&ctwnd_main, "MP3 Jukebox", "radio_gaga.mp3", "top_gun_theme.mp3");
  ////SetupCapTWindow (&ctwnd_main, "MP3 Jukebox", "", "");
  ////DrawCapTWindow (&ctwnd_main);

  ////SetupButton (&btn_ok, /*x*/(tft.width()/2)-BUTTON_WIDTH_PIXELS/2, /*y*/tft.height()-BUTTON_HEIGHT_PIXELS-6, "OK");
  ////DrawButton (&btn_ok);
  //SetupEdit (&edit_text, /*x*/20, /*y*/12, /*text_max_chars*/16, "My Radio");
  //DrawEdit (&edit_text, /*has_focus*/1);
  
  ////SetupButton (&btn_song1, /*x*/20, /*y*/tft.height()-BUTTON_HEIGHT_PIXELS*2-18, "radio_gaga.mp3");
  //SetupButton (&btn_opt1, /*x*/20, /*y*/12+EDIT_HEIGHT_PIXELS+6, "radio_gaga.mp3");
  //DrawButton (&btn_opt1, /*has_focus*/0);
  ////SetupButton (&btn_opt2, /*x*/20, /*y*/tft.height()-BUTTON_HEIGHT_PIXELS-12, "top_gun.mp3");
  //SetupButton (&btn_opt2, /*x*/20, /*y*/12+EDIT_HEIGHT_PIXELS+6+BUTTON_HEIGHT_PIXELS+6, "top_gun.mp3");
  //DrawButton (&btn_opt2, /*has_focus*/0);
  //SetupButton (&btn_opt3, /*x*/20, /*y*/tft.height()-BUTTON_HEIGHT_PIXELS*2-12, "starships.mp3");
  //DrawButton (&btn_opt3, /*has_focus*/1);

  ////void SetupList (struct list_s *lst, int x, int y, int text_max_chars, int visible_count, const char *item_prefix) {
  SetupList (&lst_nets, /*x*/20, /*y*/12, /*text_max_chars*/16, /*visible_count*/4, /*void cb_func(char *)*/&list_selected, /*item_prefix*/NULL);//"WiFi");
  //SetupLabel (&lbl_fmfreq, /*x*/154, /*y*/12+EDIT_HEIGHT_PIXELS+6+BUTTON_HEIGHT_PIXELS+6, /*max_chars "102.1"*/5, /*text_default*/fm_station_str);
  //DrawLabel (&lbl_fmfreq, /*has_focus*/0);

  // Password screen - setup elements
  SetupWindow (&wnd_plain, /*x0*/0, /*y0*/0, tft.width()-1, tft.height()-1, /*border*/0, /*buffered*/0);
  SetupLabel (&lbl_instr, /*x*/1, /*y*/1, /*max_chars*/19, /*text_default*/"Enter password for:");
  //set_net_label ("Default WiFi Name");
  SetupLabel (&lbl_net, /*x*/1, /*y*/1+LABEL_HEIGHT_PIXELS+1, /*max_chars*/16, /*text_default*/"Default WiFi Name");
  SetupEdit (&edit_pass, /*x*/1, /*y*/1+LABEL_HEIGHT_PIXELS+1+LABEL_HEIGHT_PIXELS+1, /*text_max_chars*/16, "Doyourwork!22");
  SetupButton (&btn_ok, /*x*/80, /*y*/1+LABEL_HEIGHT_PIXELS+1+LABEL_HEIGHT_PIXELS+1+EDIT_HEIGHT_PIXELS+3, "OK", /*void cb_func(void)*/&cb_passwd_ok_clicked);
  SetupButton (&btn_back, /*x*/1, /*y*/1+LABEL_HEIGHT_PIXELS+1+LABEL_HEIGHT_PIXELS+1+EDIT_HEIGHT_PIXELS+3, "Back", /*void cb_func(void)*/&cb_passwd_back_clicked);

  // App screen - setup elements
  //SetupWindow (&wnd_plain, /*x0*/0, /*y0*/0, tft.width()-1, tft.height()-1, /*border*/0, /*buffered*/0);
  //SetupCapTWindow (&ctwnd_main, "Clock", "", "");
  SetupLabel (&lbl_clock, /*x*/tft.width()-(5*LABEL_WIDTH_PIXELS)/2, /*y*/1, /*max_chars*/5, /*text_default*/"Clock");
  SetupCheckBox (&cb_lastcolon, /*x*/170, /*y*/1, /*text_str*/":", 0/*!checked_default*/, &cb_app_colon_set/*void cb_func(int check_val)*/);

  SetupButton (&btn_ip, /*x horiz*/24, /*y vert*/36, "000.000.000.000", /*void cb_func(void)*/&cb_app_ip_clicked); // force button to be big enough for full IP

  SetupLabel (&lbl_utc, /*x*/1, /*y*/69, /*max_chars*/3, /*text_default*/"UTC");
// create a new up/down control 'lst' on screen.
//  draw at upper-left corner 'x', 'y'
//  text field will contain up to 'text_max_chars'. This determines width on screen.
//  default value will be 'dfl_val'. min/max limits are 'min_val' to 'max_val'. Step size is 'val_step'.
//  when an item is chosen (with 'Enter', right-arrow, middle button, etc.), void cb_func(double sel_val) will be called.
// When displayed, 'val_prec' is the number of digits that will be displayed after the decimal.
  SetupUpDown (&updn_tzone, /*x*/60, /*y*/69, /*text_max_chars*/5, &cb_app_tzone_set/*void cb_func(double sel_val)*/, NULL/*void cb_chg_func(double chg_val)*/, /*min_val*/-12, /*max_val*/+14, /*dfl_val*/-6, /*val_step*/0.5, /*val_prec*/1);
//  SetupUpDown (&updn_tzone, /*x*/24, /*y*/80, /*text_max_chars*/5, NULL/*void cb_func(double sel_val)*/, /*min_val*/-12, /*max_val*/+14, /*dfl_val*/-0.2, /*val_step*/0.2, /*val_prec*/1);

  SetupCheckBox (&cb_daylight, /*x*/165, /*y*/69, /*text_str*/"DST", 1/*checked_default*/, &cb_app_dst_set/*void cb_func(int check_val)*/);

  SetupLabel (&lbl_brightness, /*x*/1, /*y*/100, /*max_chars*/10, /*text_default*/"Brightness");
  SetupUpDown (&updn_bright, /*x*/160, /*y*/100, /*text_max_chars*/2, NULL/*void cb_func(double sel_val)*/, &cb_app_bright_set/*void cb_chg_func(double chg_val)*/, /*min_val*/-1, /*max_val*/+16, /*dfl_val*/16, /*val_step*/1, /*val_prec*/0);

  app_prefs_get (app_settings);
  set_net_label (app_settings->ssid);
  SetEdit     (&edit_pass,   app_settings->password);
  SetCheckBox (&cb_lastcolon, app_settings->last_colon);
  SetUpDown   (&updn_tzone,  app_settings->gmt_offset_hours);
  SetCheckBox (&cb_daylight, app_settings->daylight_observed);
  SetUpDown   (&updn_bright,  app_settings->bright_steps);
  app_connect();
  ScreenDraw();
}
// ---------------------------- Manage list -----------------------------------
// set an item in the list
void set_list_item (int item_idx, const char *new_fmt, ...) {
  char new_text[LIST_MAX_TEXT];

  va_list args;
  va_start (args, new_fmt);
  vsnprintf (new_text, LIST_MAX_TEXT, new_fmt, args);
  va_end (args);

  SetListItem (&lst_nets, item_idx, new_text);
}

// add an item to the list
//  if it already exists, nothing will be added.
void add_list_item (const char *new_fmt, ...) {
  char new_text[LIST_MAX_TEXT];

  va_list args;
  va_start (args, new_fmt);
  vsnprintf (new_text, LIST_MAX_TEXT, new_fmt, args);
  va_end (args);

  AddListItem (&lst_nets, new_text);
}

// redraw the list
//  Call this after done setting/adding items.
void redraw_list (void) {
  if (lst_nets.needs_redraw) { // need to redraw the list of wifi networks (b/c we added 1 or more networks)
    ScreenRedrawCtrl(&tab_ctrl_nets);
  }
}

void list_selected(char *sel_net) {
  // Accept WiFi network
  strncpy (app_settings->ssid, sel_net, APP_SETTINGS_STR_MAX);
  // setup control on next screen with WiFi network name.
  set_net_label (sel_net);

  // Change to password screen.
  cur_screen = &pass_screen;
  ScreenDraw();
}

bool current_screen_is_wifi(void) {
  if (cur_screen == &wifi_screen) {
    return true; // we are looking at the screen that shows the wifi networks
  }
  return false;
}
// ---------------------------- WiFi Password Screen functions --------------------------
// Set WiFi Network label
void set_net_label (char *new_fmt, ...) {
  va_list args;
  va_start (args, new_fmt);
  vsnprintf (wifi_net_str, LABEL_MAX_TEXT, new_fmt, args);
  va_end (args);

  SetLabel (&lbl_net, wifi_net_str);
}

void cb_passwd_back_clicked (void) {
  // Change back to WiFi (network selection) screen.
  cur_screen = &wifi_screen;
  ScreenDraw();
}

void cb_passwd_ok_clicked (void) {
  char *password;

  // Accept WiFi password.
  password = GetEdit(&edit_pass);
  strncpy (app_settings->password, password, APP_SETTINGS_STR_MAX);

  // start trying to connect.
  app_connect();

  // Go to main app screen.
  cur_screen = &app_screen;
  ScreenDraw();
}
// ---------------------------- Main App Screen functions --------------------------
void set_ip_btn (const char *new_fmt, ...) {
  char new_text[LIST_MAX_TEXT];

  va_list args;
  va_start (args, new_fmt);
  vsnprintf (new_text, LIST_MAX_TEXT, new_fmt, args);
  va_end (args);

  SetButtonText (&btn_ip, new_text);
  ScreenRedrawCtrl(&tab_ctrl_ip);
}

bool current_screen_is_app(void) {
  if (cur_screen == &app_screen) {
    return true; // we are looking at the screen that shows the main app controls
  }
  return false;
}

void app_connect(void) {
  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(app_settings->ssid, app_settings->password);
  set_ip_btn ("Connecting");
}

bool is_wifi_connected(void) {
  if (WiFi.status() == WL_CONNECTED) {
    return true;
  }
  return false;
}
bool wifi_has_ip(void) {
  IPAddress my_ip_addr;

  my_ip_addr = WiFi.localIP();
  if (my_ip_addr[0] == 0 &&
      my_ip_addr[1] == 0 &&
      my_ip_addr[2] == 0 &&
      my_ip_addr[3] == 0) {
    return false;
  }
  return true;
}

const char* ntpServer = "pool.ntp.org";
void app_time_set (void) {
  double tzone_hr;
  int gmtOffset_sec;
  int dst_checked;
  int daylightOffset_sec = 0;

  tzone_hr = app_settings->gmt_offset_hours;//GetUpDown(&updn_tzone);
  gmtOffset_sec = tzone_hr * 3600; // convert FROM: hours offset TO: seconds offset

  dst_checked = app_settings->daylight_observed;//GetCheckBox(&cb_daylight);
  if (dst_checked) {
    daylightOffset_sec = 3600; // 1 hour
  }

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

int was_connected = 0;//-1; // force 'NO WiFi', 'NO IP' or ip address to be set
int had_ip = 0;//-1;        // force 'NO WiFi', 'NO IP' or ip address to be set
bool did_init = false;

void app_update(void) {
  bool is_connected;
  bool has_ip = false;

  if (!did_init) {
    app_connect(); // wait until now to do initial connection?
  }

  is_connected = is_wifi_connected();
  if (is_connected) {
    has_ip = wifi_has_ip();
  }
  //Serial.print("app_update did_init: ");
  //Serial.print(did_init);
  //Serial.print(", was_connected: ");
  //Serial.print(was_connected);
  //Serial.print(", is_connected: ");
  //Serial.print(is_connected);
  //Serial.print(", has_ip: ");
  //Serial.println(has_ip);
  if ((!did_init || !was_connected) && is_connected) {
    if ((!did_init || !had_ip) && has_ip) {
      IPAddress my_ip_addr;

      my_ip_addr = WiFi.localIP();
      set_ip_btn ("%d.%d.%d.%d", my_ip_addr[0], my_ip_addr[1], my_ip_addr[2], my_ip_addr[3]);

      // save successful WiFi ssid and password.
      app_prefs_put (app_settings);
#ifdef OTA_UPDATE
      over_the_air_update_setup ();
#endif
      app_time_set();
    }
    if ((!did_init || had_ip) && !has_ip) {
      set_ip_btn ("NO IP");
    }
  }
  if ((!did_init || was_connected) && !is_connected) {
    set_ip_btn ("NO WiFi");
  }
  was_connected = is_connected;
  had_ip        = has_ip;
  did_init      = true;
}

void cb_app_ip_clicked (void) {
  // Change back to WiFi (network selection) screen.
  cur_screen = &wifi_screen;
  ScreenDraw();
}

void cb_app_tzone_set (double tzone_hrs) {
 app_settings->gmt_offset_hours = tzone_hrs; 
 app_prefs_put (app_settings);
 app_time_set();
}

void cb_app_dst_set (int dst_checked) {
 app_settings->daylight_observed = dst_checked; 
 app_prefs_put (app_settings);
 app_time_set();
}

void cb_app_bright_set (double bright_steps) {
 app_settings->bright_steps = bright_steps; 
 app_prefs_put (app_settings);
 sevenseg_bright_set ();
}

void cb_app_colon_set (int colon_checked) {
 app_settings->last_colon = colon_checked; 
 app_prefs_put (app_settings);
}