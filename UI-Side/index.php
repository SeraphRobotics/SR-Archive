<html>
	<head>
		<title>Fab Visualizer</title>
		
		<script type="text/javascript" src="jquery.min.js"></script>
		<script type="text/javascript" src="jsc3d.js"></script>
		<script type="text/javascript" src="default.js"></script>
		
		<link rel="stylesheet" type="text/css" href="style.css" />
	</head>

	<body>
		<div id="container">
			<div id="header">
				<h1>Fab Visualizer</h1>
				<div id="navigation">
					<a href="#" id="projects-link" class="nav-link">Projects</a>
				</div>
			</div>
			<div id="projects-view">
				<a href="#" class="half-opacity project-link">Load</a>  <a href="#" id="new-project-link" class="project-link">New (+)</a>
				<div id="list-overflow-cutoff">
					<ul>
						<li class="project-entry">dragon.stl</li>
						<li class="project-entry">teapot.stl</li>
						<li class="project-entry">teapot.stl</li>
						<li class="project-entry">teapot.stl</li>
						<li class="project-entry">teapot.stl</li>
						<li class="project-entry">teapot.stl</li>
						<li class="project-entry">teapot.stl</li>
						<li class="project-entry">teapot.stl</li>
						<li class="project-entry">teapot.stl</li>
						<li class="project-entry">teapot.stl</li>
						<li class="project-entry">teapot.stl</li>
					</ul>
				</div>
				<canvas id="project-preview" width="305" height="215"></canvas>
				<div id="project-details">
					<p><strong>Name:</strong> Dragon</p>
					<p><strong>File:</strong> dragon.stl</p>
					<p><strong>Material:</strong> foamcut</p>
					<p><strong>Last Modified:</strong> March 31, 2012</p>
				</div>
			</div>
			
			<div id="content">
				<div id="container-left">
					<textarea id="command-text"></textarea>
					<a id="submit-commands" href="#">Render</a>
				</div>
				
				<div id="container-right">
					<div id="top-default-view">
						<canvas id="default-view" height="360px" width="468px"></canvas>
					</div>
					<div id="quad-view-container">
						<canvas class="view-box" height="172px" width="218px" id="top-view"></canvas>
						<canvas class="view-box" height="172px" width="218px" id="front-view"></canvas>
						<canvas class="view-box" height="172px" width="218px" id="side-view"></canvas>
						<canvas class="view-box" height="172px" width="218px" id="perspective-view"></canvas>
					</div>
				</div>
			</div>
			
		</div>
	</body>
</html>