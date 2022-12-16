module ncnn_mnist
    implicit none
    
    interface
        subroutine predict(image, label_pred) bind(c)
            use iso_c_binding, only: c_float
            implicit none
            
            real(c_float), intent(in)::image(28, 28)
            integer, intent(out)::label_pred
        
        end subroutine predict

    end interface

contains
    
end module ncnn_mnist