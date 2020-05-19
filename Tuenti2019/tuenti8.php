<?php

function create_auth_cookie($user)
{
    // Nill's auth Cookie = 1c919b2d62b178f3c713bb5431c57cc1 -> authkey -> Admin's auth Cookie
    $authKey = '8e798f0377c99bc0';
    if (!$authKey) {
        return false;
    }
    $userMd5 = md5($user, true);

    $result = '';
    for ($i = 0; $i < strlen($userMd5); $i++) {
        $result .= bin2hex(chr((ord($authKey[$i]) + ord($userMd5[$i])) % 256));
    }
    return $result;
}

$user = 'admin';
print(create_auth_cookie($user));

// Ultimate secret dish is SpaguettiAndChocolatePizzaWithBroccoli
