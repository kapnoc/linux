
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <time.h>

#include "../kselftest_harness.h"

TEST(sys_uptime)
{
	time_t t = -1;

	syscall(441, &t);
	ASSERT_GT(t, -1) TH_LOG("uptime should give > -1");

	t = syscall(441, NULL);
	ASSERT_GT(t, -1) TH_LOG("uptime should return > -1");
}

TEST_HARNESS_MAIN