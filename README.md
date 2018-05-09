exp-html-skeleton
===

Expansive HTML skeleton plugin.

This provides:

 * Configuration for Expansive plugins: 
    * [exp-blog](https://github.com/embedthis/exp-blog) for basic blogging
    * [exp-canon](https://github.com/embedthis/exp-canon) to emit canonical link references
    * [exp-css](https://github.com/embedthis/exp-css) for CSS files
    * [exp-html](https://github.com/embedthis/exp-html) to minify HTML files
    * [exp-less](https://github.com/embedthis/exp-less) for Less files
    * [exp-js](https://github.com/embedthis/exp-js) for script files
    * [exp-markdown](https://github.com/embedthis/exp-markdown) for Markdown files
    * [exp-reload](https://github.com/embedthis/exp-reload) for dynamic browser reloading
    * [jquery](https://github.com/jquery/jquery) for client side DOM manipulation
 * Default layout 
 * Default partials for header, navigation and footer
 * Starter home page

### To install:

    pak install exp-html-skeleton

### Description

The HTML skeleton is a basic starter skeleton for Expansive. It provides a default layout, partial pages and is configured to use Less stylesheets. Extensions are installed to process less stylesheets and minify scripts.

The skeleton is configured for a "debug" and "release" mode of operation via the "pak.mode" property in package.json. By default, debug mode will disable minification and mangling of scripts.

### Configure

#### expansive.json

* canon.enable &mdash; Enable the canon service to emit canonical link elements for index pages.
* less.enable &mdash; Enable the less service to process less files.
* less.dependencies &mdash; Explicit map of dependencies if not using "stylesheet". 
* less.files &mdash; Array of less files to compile.
* less.stylesheet &mdash; Primary stylesheet to update if any less file changes.
    If specified, the "dependencies" map will be automatically created. 

* css.dotmin &mdash; Use '.min.css' as the output file extension after minification. Otherwise will be
    '.css'.  Default to true.
* css.enable &mdash; Enable processing CSS files. Defaults to true.

* js.compress &mdash; Enable compression of script files. Defaults to true.
* js.dotmin &mdash; Set '.min.js' as the output file extension after minification. Otherwise will be '.js'. Defaults to true.
* js.enable &mdash; Enable minifying script files. Defaults to true.
* js.force &mdash; Force the minification of script files regardless of whether a minified version already exists. Defaults to false.
* js.extract &mdash; Filename to contain extracted inline scripts. Defaults to false.
* js.mangle &mdash; Enable mangling of Javascript variable and function names. Defaults to true.
* js.minify &mdash; Enable minifying of Javascript files. Default to false.
* js.usemap &mdash; Use minified Javascript if corresponding source maps is present. Default to true.
* js.usemin &mdash; Use minified Javascript if present. Default to true.
* html.enable &mdash; Enable minifying HTML files.
* html.options &mdash; Command line options to html-minifier.

```
{
    services: {
        'less': {
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
        'html': {
            'enable': false
        }
    }
}
```

### Get Pak from

[https://www.embedthis.com/pak/](https://www.embedthis.com/pak/)
