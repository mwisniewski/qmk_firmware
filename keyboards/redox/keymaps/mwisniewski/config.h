#pragma once

// Ustawienia USB dla stabilnego połączenia
#define USB_POLLING_INTERVAL_MS 1
#define USB_SUSPEND_WAKEUP_DELAY 0

// Zwiększenie timeoutu dla inicjalizacji USB
#define USB_MAX_POWER_CONSUMPTION 500

// Ustawienia dla split keyboard
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000
#define SPLIT_USB_TIMEOUT_POLL 10

// Dodatkowe ustawienia stabilności
#define DEBOUNCE 5
#define USB_SUSPEND_WAKEUP_DELAY 0

// Opcjonalnie: jeśli używasz VBUS detection
#define SPLIT_USB_DETECT_DELAY 100

// EE_HANDS jest już zdefiniowane w głównym config.h rev1
// Jeśli EE_HANDS nie działa, odkomentuj jedną z linii poniżej:
// #define MASTER_LEFT    // Lewa strona zawsze master (podłączona do USB)
// #define MASTER_RIGHT   // Prawa strona zawsze master (podłączona do USB)
