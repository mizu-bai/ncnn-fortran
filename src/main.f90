program main
    use ncnn_mnist, only: predict
    implicit none
    
    real :: image(28, 28)
    character(len=80) :: image_name
    integer :: i, label_pred, argc

    !> parse input
    argc = iargc()

    if (argc /= 1) then
        print *, "Usage: ./mnist image.dat"
        stop
    end if

    call getarg(1, image_name)

    !> open file
    open(unit=11, file=image_name, status="old")

    !> read image
    do i = 1, 28
        read(11, *) image(:, i)
    end do

    !> call ncnn
    call predict(image, label_pred)

    !> result
    print *, "Predict: ", label_pred

    !> remember to close file
    close(11)

end program main