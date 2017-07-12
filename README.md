# php-embed-windows
PHP Embed SAPI on Windows

## Build PHP7 On windows

You can read the [tutorial](https://wiki.php.net/internals/windows/stepbystepbuild_sdk_2) about how to build PHP7.2 On Windows.

## Build Embed SAPI on Windows

git clone this project

``` https://github.com/yanghuxiao/php-embed-windows.git ```

open php-embed-windows.sln (In Visual Studio 2017)

```
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
```

NOTE:defind ZTS,PHP_WIN32,ZEND_WIN32