#ifndef _NET_HTTPD_H__
#define _NET_HTTPD_H__

//extern int (*current_flash_erase_write)(char *buf, unsigned int offs, int count);

void HttpdStart(void);
void HttpdHandler(void);

/* board specific implementation */
extern int do_http_upgrade(const ulong size, const int upgrade_type);
extern int do_http_progress(const int state);
extern void LED_ALERT_ON(void);
extern void LED_ALERT_OFF(void);

#endif
