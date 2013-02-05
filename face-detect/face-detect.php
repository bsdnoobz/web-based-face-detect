<?php
if (isset($_SERVER['HTTP_X_FILENAME'])) 
{
	$file = 'uploads/'.$_SERVER['HTTP_X_FILENAME'];
	file_put_contents("$file", file_get_contents("php://input"));

	$cmd  = 'face-detect --input="'.$file.'" --outdir="'.dirname($file).'"';
	$last = exec($cmd, &$out);

	if (strpos($last, 'Error:') === false)
	{
		$res = array('success' => true);

		foreach ($out as $i => $line)
		{
			if (preg_match('/\d+,\s*([^\s]+)\s+\((\d+)x(\d+)\)/i', $line, $m))
				$res['images'][] = array('src' => $m[1], 'width' => $m[2], 'height' => $m[3]);
		}
	}
	else
		$res = array('success' => false, 'msg' => $last);

	header('Content-Type: application/json');
	echo json_encode($res);
} 
else
{
	header('HTTP/1.1 404 Not found');
	header('Content-Type: application/json');
	echo json_encode(array(
		'success' => false,
		'msg' => '404 - The resource you requested is not found.'
	));
}
