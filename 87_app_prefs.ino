// Preferences namespace where app settings are stored

#define PREFS_CREDS_SECTION "credentials"
#define PREFS_TIME_SECTION  "time"

#define APP_SETTINGS_STR_MAX 100

struct app_settings_s {
  // 'credentials' section
  char ssid    [APP_SETTINGS_STR_MAX];
  char password[APP_SETTINGS_STR_MAX];
  // 'time' section
  bool daylight_observed;
  double  gmt_offset_hours;
};

struct app_settings_s app_settings[1];

Preferences preferences;

void app_prefs_put (struct app_settings_s *app_settings) {
  preferences.begin(PREFS_CREDS_SECTION, false /*not read-only*/);
  preferences.putString("ssid",     app_settings->ssid); 
  preferences.putString("password", app_settings->password);
  preferences.end(); // let other namespaces be used later.

  preferences.begin(PREFS_TIME_SECTION, false /*not read-only*/);
  preferences.putBool("daylight_observed", app_settings->daylight_observed);
  preferences.putDouble("gmt_offset_hours", app_settings->gmt_offset_hours);
  preferences.end(); // let other namespaces be used later.
}

void app_prefs_get (struct app_settings_s *app_settings) {
  preferences.begin(PREFS_CREDS_SECTION, true /*read-only*/);
  preferences.getString("ssid",     app_settings->ssid,     APP_SETTINGS_STR_MAX); 
  preferences.getString("password", app_settings->password, APP_SETTINGS_STR_MAX);
  preferences.end(); // let other namespaces be used later.

  preferences.begin(PREFS_TIME_SECTION, true /*read-only*/);
  app_settings->daylight_observed = preferences.getBool("daylight_observed", true/*default to observing Daylight Saving Time*/);
  app_settings->gmt_offset_hours = preferences.getInt("gmt_offset_hours", -6/*default to USA Central Standard Time (CST)*/);
  preferences.end(); // let other namespaces be used later.
}