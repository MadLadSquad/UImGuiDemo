//// Code from https://github.com/jnmaloney/WebGui licensed under the MIT license
//var Module = {
//    preRun: [],
//    postRun: [],
//    print: (function() {})(),
//    printErr: function(text) {},
//    canvas: (function() {
//        const canvas = document.getElementById('canvas');
//        // As a default initial behavior, pop up an alert when webgl context is lost. To make your
//        // application robust, you may want to override this behavior before shipping!
//        // See http://www.khronos.org/registry/webgl/specs/latest/1.0/#5.15.2
//        canvas.addEventListener("webglcontextlost", function(e) { alert('WebGL context lost. You will need to reload the page.'); e.preventDefault(); }, false);
//        return canvas;
//    })(),
//    setStatus: function(text) {},
//    totalDependencies: 0,
//    monitorRunDependencies: function(left) {}
//};
//window.addEventListener('resize', js_resizeCanvas, false);
//function js_resizeCanvas() {
//    document.getElementById('canvas').width = window.innerWidth;
//    document.getElementById('canvas').height = window.innerHeight;
//}