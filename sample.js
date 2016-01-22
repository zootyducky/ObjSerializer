var readMesh = Module.cwrap('readMesh','number',['string']);
readMesh('objData/yd.data');

var readMeshFromUrl = Module.cwrap('readMeshFromUrl','number',['string','string']);

var timeCheck = function(){
    start_o = Date.now();
    readMeshFromUrl('https://s3-ap-northeast-1.amazonaws.com/realityreflection/aaa/final.data','aaa');
    
}

timeCheck();




  var renderer = null,
        scene = null,
        camera = null,
        cube = null;

    var duration = 5000; // ms
    var currentTime = Date.now();
    
    

    function animate() {

        var now = Date.now();
        var deltat = now - currentTime;
        currentTime = now;
        var fract = deltat / duration;
        var angle = Math.PI * 2 * fract;
        cubeMesh.rotateX = cubeMesh.rotation.x + angle;
        
    }

    function run() {
        requestAnimationFrame(function () {
            run();
        });

        // Render the scene
        renderer.render(scene, camera);
        // Spin the cube for next frame
        animate();

    }
    

    $(document).ready(
        function () {
            var canvas = document.getElementById("webglcanvas");

            // Create the Three.js renderer and attach it to our canvas
            renderer = new THREE.WebGLRenderer({
                canvas: canvas,
                antialias: true
            });

            // Set the viewport size
            renderer.setSize(canvas.width, canvas.height);

            // Create a new Three.js scene
            scene = new THREE.Scene();

            // Add  a camera so we can view the scene
            camera = new THREE.PerspectiveCamera(45, canvas.width / canvas.height, 1, 4000);
            camera.position.x = 1;
            camera.position.y = 1;
            camera.position.z = 1;

            scene.add(camera);

            // Add a directional light to show off the object
            var light = new THREE.DirectionalLight(0xffffff, 1.5);

            // Position the light out from the scene, pointing at the origin
            light.position.set(0, 0, 1);
            scene.add(light);

            var geometry = new THREE.BufferGeometry();
            var buf;

            var cube = new THREE.BoxGeometry(1, 1, 1);
            var cubeMaterial = new THREE.MeshBasicMaterial({
                color: 0x00fff0
            });
            cubeMesh = new THREE.Mesh(cube, cubeMaterial);
//            scene.add(cubeMesh);
//            camera.lookAt(cubeMesh);

            // Run the run loop
            run();
          
        }
    );