
#include <linux/syscalls.h>
#include <linux/ktime.h>
#include <linux/time64.h>

SYSCALL_DEFINE1(uptime, time64_t __user *, t)
{
	time64_t seconds;

	seconds = ktime_get_boottime_seconds();
	if (t != (time64_t *)0) {
		*t = seconds;
	}
	return seconds;
}