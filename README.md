exp-html-skeleton
===

Expansive HTML skeleton plugin.

This provides:

 * Configuration for Expansive plugins: 
    * [exp-blog](https://github.com/embedthis/exp-blog) for basic blogging
    * [exp-css](https://github.com/embedthis/exp-css) for CSS files
    * [exp-less](https://github.com/embedthis/exp-less) for Less files
    * [exp-js](https://github.com/embedthis/exp-js) for script files
    * [exp-md](https://github.com/embedthis/exp-md) for Markdown files
    * [exp-reload](https://github.com/embedthis/exp-reload) for dynamic browser reloading
 * Default layout 
 * Default partials for header, navigation and footer
 * Starter home page

### To install:

    pak install exp-html-skeleton

### Description

The HTML skeleton is a basic starter skeleton for Expansive. It provides a default layout,
partial pages and is configured to use Less stylesheets. Extensions are installed
to process less stylesheets and minify scripts.

The skeleton is configured for a "debug" and "release" mode of operation via the 
"mode" property in package.json. By default, debug mode will disable minification and
mangling of scripts.

### Configure

#### expansive.json

* compile-less-css.enable &mdash; Enable the compile-less-css service to process less files.
* compile-less-css.stylesheet &mdash; Primary stylesheet to update if any less file changes.
    If specified, the "dependencies" map will be automatically created. 
* compile-less-css.dependencies &mdash; Explicit map of dependencies if not using "stylesheet". 
* compile-less-css.documents &mdash; Array of less files to compile.

* css.dotmin &mdash; Use '.min.css' as the output file extension after minification. Otherwise will be
    '.css'.  Default to true.
* css.enable &mdash; Enable processing CSS files. Defaults to true.

* js.compress &mdash; Enable compression of script files. Defaults to true.
* js.dotmin &mdash; Set '.min.js' as the output file extension after minification. Otherwise will be '.js'. Defaults to true.
* js.enable &mdash; Enable minifying script files. Defaults to true.
* js.force &mdash; Force the minification of script files regardless of whether a minified version already exists. Defaults to false.
* js.inline &mdash; Filename to contain extracted inline scripts. Defaults to null.
* js.mangle &mdash; Enable mangling of Javascript variable and function names. Defaults to true.
* js.minify &mdash; Enable minifying of Javascript files. Default to false.
* js.usemap &mdash; Use minified Javascript if corresponding source maps is present. Default to true.
* js.usemin &mdash; Use minified Javascript if present. Default to true.
* minify-html.enable &mdash; Enable minifying HTML files.
* minify-html.options &mdash; Command line options to html-minifier.
    to disable the use of minified resources.

```
{
    services: {
        'compile-less-css': {
            enable: true,
            stylesheet: 'css/all.css',
            dependencies: { 'css/all.css.less' : '**.less' },
            documents: [ '!**.less', '**.css.less' ]
        },
        'css': {
            dotmin:     false,
        },
        'js': {
            compress:   true,
            mangle:     true,
            dotmin:     false,
        },
        'minify-html': {
            'enable': false
        }
    }
}
```

### Get Pak from

[https://embedthis.com/pak/](https://embedthis.com/pak/)
