#ifndef RUMTIME_ERROR_H_INCLUDED
#define RUMTIME_ERROR_H_INCLUDED

void RuntimeError(const char *message, int parameter,
				  const char *file, int line);

#define RUNTIME_ERROR(description, parameter) \
	RuntimeError(description, parameter, __FILE__, __LINE__)


#endif /* RUMTIME_ERROR_H_INCLUDED */
