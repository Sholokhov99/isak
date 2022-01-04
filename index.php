<?php

require_once __DIR__ ."/transformationarr.php";

$transform = new \Isak\Work\TransformationArr();
$transform->main();
echo $transform->getInfoToString();
?>