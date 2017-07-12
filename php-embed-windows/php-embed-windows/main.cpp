#include "stdafx.h"
#include <sapi/embed/php_embed.h>

#pragma comment(lib,"php7embed.lib")

int main(int argc, char *argv[])
{
	PHP_EMBED_START_BLOCK(0, NULL);
	char * script = "file_put_contents('a.txt', time()); print 'Hello World!';";
	zend_eval_string(script, NULL,
		"Simple Hello World App" TSRMLS_CC);
	PHP_EMBED_END_BLOCK();

	return 0;
}