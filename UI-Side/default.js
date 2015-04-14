$(document).ready(function() {

	$('#projects-link').click( function(e) {
		if ( $('#projects-view').is(':visible') ) {
			$(this).removeClass('nav-link-active');
			$('.project-entry').removeClass('active-project-link');
			$('#projects-view').slideUp();
		}
		else if ( !$('#projects-view').is(':visible') ) {
			$(this).addClass('nav-link-active');
			$('#projects-view').slideDown();
			e.stopPropagation();
		}
	});
	
	// $('html').click( function(e) {
		// $('#projects-link').removeClass('nav-link-active');
		// $('#projects-view').slideUp();
	// });

	$('.project-entry').click( function() {
		$('.project-entry').removeClass('active-project-link');
		console.log("moo");
		$(this).addClass('active-project-link');
	});


	function setViewer( canvasID, xrot, yrot, zrot ) {
	
		var canvas = document.getElementById( canvasID );

		var viewer = new JSC3D.Viewer(canvas);
	
		viewer.enableDefaultInputHandler(false);
		viewer.setParameter('SceneUrl', 'models/dragon.stl');
		viewer.setParameter('InitRotationX', xrot);
		viewer.setParameter('InitRotationY', yrot);
		viewer.setParameter('InitRotationZ', zrot);
		viewer.setParameter('ModelColor', '#CAA618');
		viewer.setParameter('BackgroundColor1', '#040404');
		viewer.setParameter('BackgroundColor2', '#131313');
		viewer.setParameter('RenderMode', 'smooth');

		viewer.init();
		viewer.update();

	}
	
	setViewer( 'default-view',     -20, 20, 0);
	setViewer( 'top-view',           -90,  0, 0);
	setViewer( 'side-view',          0,  0, 0);
	setViewer( 'front-view',         0, 90, 0);
	setViewer( 'perspective-view',  -40, 30, 25);

});