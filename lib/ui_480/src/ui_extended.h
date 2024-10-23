#ifndef UIEXTENDED_H
#define UIEXTENDED_H

extern int satsBrl;
extern bool hasWifi;
extern char ui_state;
extern char ui_action;

enum ui_command {
    Iddle,
    Expresso,
    Coffe,
    Water,    
    Beans,    
    StartStop,
    Cancel,
    WhaitPay,
    WhaitInvoice,
    Serving,
    Error,
    On
};
#endif
