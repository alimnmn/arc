	void ark (void)
	{
		HAL_TIM_Base_Start(&htim4);
		htim4.Instance->CNT = 0;
		HAL_ADC_Start(&hadc1);
		HAL_Delay(1);
		oku[1]=HAL_ADC_GetValue(&hadc1);
		zaman[1]=TIM4->CNT;
		if ((oku[1]<3500 && oku[1]>2500)){
			HAL_TIM_Base_Start(&htim4);
			htim4.Instance->CNT = 0;
			HAL_Delay(1);
			oku[2]=HAL_ADC_GetValue(&hadc1);
			zaman[2]=TIM4->CNT;
			int fark = zaman[2] - zaman[1];
			if ((oku[2]<3500 && oku[2]>2800) && fark <9){
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
				HAL_Delay(200);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
				oku[0]=0;oku[1]=0;oku[2]=0; fark=0; zaman[0]=0; zaman[1]=0; zaman[2]=0;
			}
		}
	}
