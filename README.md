exp-html-skeleton
===

Expansive HTML skeleton plugin.

This provides:

 * Configuration for Expansive plugins: 
    * [exp-css](https://github.com/embedthis/exp-css) for CSS files
    * [exp-less](https://github.com/embedthis/exp-less) for Less files
    * [exp-j](https://github.com/embedthis/exp-js) for script files
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
* prefix-css.enable &mdash; Enable running autoprefixer on CSS files to handle browser specific extensions.
* minify-css.enable &mdash; Enable minifying CSS files.
* minify-js.enable &mdash; Enable minifying script files.
* minify-js.files &mdash; Array of files to minify. Files are relative to 'source'.
* minify-js.compress &mdash; Enable compression of script files.
* minify-js.mangle &mdash; Enable mangling of Javascript variable and function names.
* minify-js.dotmin &mdash; Set '.min.js' as the output file extension after minification. Otherwise will be '.js'.
* minify-js.exclude &mdash; Array of files to exclude from minification. Files are relative to 'source'.

```
{
    services: {
        'compile-less-css': {
            enable: true,
            stylesheet: 'css/all.css',
            dependencies: { 'css/all.css.less' : '**.less' },
            documents: [ '!**.less', '**.css.less' ]
        },
        'prefix-css': {
            enable: true,
        },
        'minify-css': {
            enable: true,
        },
        'minify-js': {
            enable: true,
            files:      null,
            compress:   true,
            mangle:     true,
            dotmin:     false,
            exclude:    []
        }
    }
}
```

### Get Pak from

[https://embedthis.com/pak/](https://embedthis.com/pak/download.html)
