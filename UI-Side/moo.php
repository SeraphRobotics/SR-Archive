
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">

<HTML>

 <HEAD>

  <TITLE> JSC3D - Test </TITLE>

  <META NAME="Author" CONTENT="JSC3D">

 </HEAD>



 <BODY>

	<div style="width:490px; margin:auto; position:relative; font-size: 9pt; color: #777777;">

		<canvas id="cv" style="border: 1px solid;" width="490" height="368" ></canvas>

		<div id="tip" style="display:block; color:#ffffff; padding:5px; position:absolute; left:10px; top:315px; background-color:#000000; height:32px; width:250px; border-radius:5px; border:1px solid #777777; font-family:Arial,sans-serif; opacity:0.5;">

			Drag mouse to rotate <br> Drag mouse with shift pressed to zoom

		</div>

		<div style="float:left;">

		<select id="model_list">

		<option>teapot.obj</option>

		<option>shoe.obj</option>

		<option>bunny.obj</option>

		<option>buddha.obj</option>

		<option>dragon.stl</option>

		<option>shoelast.obj</option>

		<option>hard_milk.stl</option>

		<option>helicopter.obj</option>

		</select>

		<button id="load" onclick="loadModel();">Load</button>

		</div>

		<div style="float:right;">

		<select id="render_mode_list">

		<option>render as points</option>

		<option>render as wireframe</option>

		<option>render as flat</option>

		<option>render as smooth</option>

		<option>render with environment</option>

		</select>

		<button id="change" onclick="setRenderMode();">Change</button>

		</div>

	</div>

	<script type="text/javascript" src="jsc3d.js"></script>

	<script type="text/javascript">

	var canvas = document.getElementById('cv');

	var viewer = new JSC3D.Viewer(canvas);

	var logoTimerID = 0;

	viewer.setParameter('SceneUrl', 'models/jsc_logo.obj');

	viewer.setParameter('InitRotationX', -20);

	viewer.setParameter('InitRotationY', 20);

	viewer.setParameter('InitRotationZ', 0);

	viewer.setParameter('ModelColor', '#CAA618');

	viewer.setParameter('BackgroundColor1', '#FFFFFF');

	viewer.setParameter('BackgroundColor2', '#383840');

	viewer.setParameter('RenderMode', 'smooth');

	viewer.setParameter('SphereMapUrl', 'models/chrome.jpg');

	viewer.init();

	viewer.update();



	viewer.enableDefaultInputHandler(false);

	logoTimerID = setInterval( function() {

		viewer.rotate(0, 10, 0);

		viewer.update();

	}, 100);

	setTimeout( function() {

		viewer.enableDefaultInputHandler(true);

		if(logoTimerID > 0)

			loadModel();

	}, 8000);



	var ctx = canvas.getContext('2d');

	ctx.font = '12px Courier New';

	ctx.fillStyle = '#FF0000';

	viewer.afterupdate = function() {

		if(logoTimerID > 0)

			return;



		var scene = viewer.getScene();

		if(scene != null && scene.getChildren().length > 0) {

			var objects = scene.getChildren();

			var totalFaceCount = 0;

			var totalVertexCount = 0

			for(var i=0; i<objects.length; i++) {

				totalFaceCount += objects[i].faceCount;

				totalVertexCount += objects[i].vertexBuffer.length / 3;

			}

			ctx.fillText(totalVertexCount.toString() + ' vertices', 10, 20);

			ctx.fillText(totalFaceCount.toString() + ' faces', 10, 35);

		}

	};



	function loadModel() {

		if(logoTimerID > 0) {

			clearInterval(logoTimerID);

			logoTimerID = 0;

			viewer.enableDefaultInputHandler(true);

		}

		var models = document.getElementById('model_list');

		viewer.replaceSceneFromUrl('models/' + models[models.selectedIndex].innerHTML);

		viewer.update();

	}



	function setRenderMode() {

		if(logoTimerID > 0)

			return;

		var modes = document.getElementById('render_mode_list');

		switch(modes.selectedIndex) {

		case 0:

			viewer.setRenderMode('point');

			break;

		case 1:

			viewer.setRenderMode('wireframe');

			break;

		case 2:

			viewer.setRenderMode('flat');

			break;

		case 3:

			viewer.setRenderMode('smooth');

			break;

		case 4:

			viewer.setRenderMode('texturesmooth');

			var scene = viewer.getScene();

			if(scene) {

				var objects = scene.getChildren();

				for(var i=0; i<objects.length; i++)

					objects[i].isEnvironmentCast = true;

			}

			break;

		default:

			viewer.setRenderMode('flat');

			break;

		}

		viewer.update();

	}

  </script>

 </BODY>

</HTML>
