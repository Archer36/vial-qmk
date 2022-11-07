RGB_MATRIX_EFFECT(my_per_key_rgb)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool my_per_key_rgb(effect_params_t* params) {
	HSV hsvRed = {0, 255, 63};
	RGB rgb;
	rgb = hsv_to_rgb(hsvRed);
	
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
	
	// Set mute button to red
	rgb_matrix_set_color(0, rgb.r, rgb.g, rgb.b);

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
