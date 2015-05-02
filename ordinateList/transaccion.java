abstract class Transaccion{

   public void TransaccionBancaria(){
	  System.out.println("transaccion iniciada");
	  realizarTransaccion();
	  System.out.println("transaccion completada");
   }


   protected void realizarTransaccion();

}


class Transferencia extends Transaccion{
   protected void realizarTransaccion(){
		 System.out.println("Se realiza una transferencia");
   }

}


class Pago extends Transaccion{
   protected void realizarTransaccion(){
		 System.out.println("Se realiza un pago");
   }

}
