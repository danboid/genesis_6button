void run_genesis_controller(void)
{
    CCP = 0xD8;
    CLKCTRL_MCLKCTRLB = 0x0001;  // Prescaler enabled with 1/2.

    PORTA_DIR = _BV(4) | _BV(7);     // PA4 and PA7 as outputs.
    PORTA_PIN5CTRL |= PORT_PULLUPEN_bm; // Pin 5 pulled up.

    pins_3button();

    // Wait to make sure we give time for MODE to rise
    th_wait();
    th_wait();
    th_wait();
    th_wait();

    if (0 == (PORTA_IN & _BV(5)))
    {
        // MODE button held, stay in 3-button forever
        while (true)
        {
            // loop forever
        }
    }

    while (true)
    {
        pins_3button();
        th_wait_for_low();
        th_wait_for_high();
        start_timer();
        th_wait_for_low();
        if (timeout) { continue; }
        th_wait_for_high();
        if (timeout) { continue; }
        th_wait_for_low();
        pins_low();
        if (timeout) { continue; }
        th_wait_for_high();
        pins_xyz();
        if (timeout) { continue; }
        th_wait_for_low();
        pins_high();

        while (!timeout)
        {
            // Wait for timeout to start the cycle again.
        }
    }
}
