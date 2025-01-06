// Preferences namespace where app settings are stored

#define PREFS_CREDS_SECTION "credentials"
#define PREFS_TIME_SECTION  "time"
#define PREFS_DISPLAY_SECTION  "display"

#define APP_SETTINGS_STR_MAX 100

struct app_settings_s {
  // 'credentials' section
  char ssid    [APP_SETTINGS_STR_MAX];
  char password[APP_SETTINGS_STR_MAX];
  // 'time' section
  bool daylight_observed;
  double  gmt_offset_hours;
  int bright_steps;
  bool last_colon;
};

struct app_settings_s app_settings[1];

Preferences preferences;

void app_prefs_put (struct app_settings_s *app_settings) {
  Serial.println("Writing preferences...");
  preferences.begin(PREFS_CREDS_SECTION, false /*not read-only*/);
  preferences.putString("ssid",     app_settings->ssid); 
  preferences.putString("password", app_settings->password);
  preferences.end(); // let other namespaces be used later.

  preferences.begin(PREFS_TIME_SECTION, false /*not read-only*/);
  preferences.putBool("daylight_observed", app_settings->daylight_observed);
  preferences.putDouble("gmt_offset_hours", app_settings->gmt_offset_hours);
  preferences.end(); // let other namespaces be used later.

  preferences.begin(PREFS_DISPLAY_SECTION, false /*not read-only*/);
  preferences.putInt("bright_steps", app_settings->bright_steps);
  preferences.putBool("last_colon", app_settings->last_colon);
  preferences.end(); // let other namespaces be used later.
}

void app_prefs_get (struct app_settings_s *app_settings) {
  Serial.println("Reading preferences...");

  preferences.begin(PREFS_CREDS_SECTION, true /*read-only*/);
  preferences.getString("ssid",     app_settings->ssid,     APP_SETTINGS_STR_MAX); 
  preferences.getString("password", app_settings->password, APP_SETTINGS_STR_MAX);
  preferences.end(); // let other namespaces be used later.

  preferences.begin(PREFS_TIME_SECTION, true /*read-only*/);
  app_settings->daylight_observed = preferences.getBool("daylight_observed", true/*default to observing Daylight Saving Time*/);
  app_settings->gmt_offset_hours = preferences.getInt("gmt_offset_hours", -6/*default to USA Central Standard Time (CST)*/);
  preferences.end(); // let other namespaces be used later.

  preferences.begin(PREFS_DISPLAY_SECTION, true /*read-only*/);
  app_settings->bright_steps = preferences.getInt("bright_steps", 16/*full brightness*/);
  app_settings->last_colon = preferences.getInt("last_colon", false);
  preferences.end(); // let other namespaces be used later.

  Serial.println("Read:");
  Serial.print("ssid: ");
  Serial.println(app_settings->ssid);
  Serial.print("password: ");
  Serial.println(app_settings->password);

  Serial.print("daylight_observed: ");
  Serial.println(app_settings->daylight_observed);
  Serial.print("gmt_offset_hours: ");
  Serial.println(app_settings->gmt_offset_hours);

  Serial.print("bright_steps: ");
  Serial.println(app_settings->bright_steps);
  Serial.print("last_colon: ");
  Serial.println(app_settings->last_colon);
}