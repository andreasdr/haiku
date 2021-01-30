/* Public domain. */

#ifndef _LINUX_PWM_H
#define _LINUX_PWM_H

#include <haiku-defs.h>
//#include <sys/errno.h>
#include <linux/err.h>

struct pwm_device;

inline struct pwm_device *
pwm_get(struct device *dev, const char *consumer)
{
	return ERR_PTR(-ENODEV);
}

inline void
pwm_put(struct pwm_device *pwm)
{
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline unsigned int
pwm_get_duty_cycle(const struct pwm_device *pwm)
{
//	return 0;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline int
pwm_config(struct pwm_device *pwm, int duty_ns, int period_ns)
{
//	return -EINVAL;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline int
pwm_enable(struct pwm_device *pwm)
{
//	return -EINVAL;
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void
pwm_disable(struct pwm_device *pwm)
{
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

inline void
pwm_apply_args(struct pwm_device *pwm)
{
	printf("%s::%i", __FILE__, __LINE__);
	for (int i = 0; ; i++);
}

#endif
