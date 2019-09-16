#!/bin/sh

main_menu()
{
      while :
      do
      
      echo "\nMENU:\n\t1.Create address book\n\t2.Display address book\n\t3.Insert a record\n\t4.Delete a record\n\t5.Modify a record\n\t6.Exit\nEnter your choice:\c"

      read choice

      case "$choice" in

            1)   create ;;
            
            2)   display ;;
                 
            3)   insert ;;
            
            4)   delete ;;
            
            5)   modify ;;
            
            6)   exit ;;
            *)   echo "Invalid options"
      esac
done
}

create()
{
      echo "\n"
      echo "Enter name of the address book file:"
      read  abfile
      touch $abfile
    
      echo "Address book created successfully\n"
      echo "\nFirst Name\t\tLast Name\t\t\tCity\t\t  Pincode\t\tState" >>$abfile
      echo "----------------------------------------------------------------------------------------------------------------" >>$abfile
}

display()
{
      cat $abfile
}

insert()
{
      
      echo "\n"
      echo "First Name->"
      read frname
      
      if [ -z "$frname" ]
      then
      echo "First name is empty"
      echo "Re-enter first name"
      read  frname 
      fi
      
      echo "Last Name->"
      read lsname
  
      echo "City->"
      read city

      echo "Pincode->"
      read pincode
      
      if [ -z "$pincode" ]
      then
      echo "Pincode is empty"
      echo "Re-enter pincode"
      read  pincode 
      fi

      echo "State->"
      read state
      
      echo  $frname"\t\t\t"$lsname"\t\t\t"$city"\t\t"$pincode"\t\t\t"$state >> $abfile

}

delete()
{
      echo "Enter the last name of the person whose record is to be deleted:"
      read  dname
      
      if(grep $dname $abfile)
      then
      
            sed -i "/$dname/d" $abfile
            echo "Deleted"
            
      else
            echo "Record not found"
            
      fi
}

modify()
{
      echo "Enter last name of the record to be modified:"
      read mname
      echo "\n"
      
      if(grep $mname $abfile)
      then
            sed -i "/$mname/d" $abfile
            echo "\nEnter the new first name:"
            read new_fname
            echo "\nEnter the new last name:"
            read new_lname
            echo "Enter the new city:"
            read new_city
            echo "Enter the new pincode:"
            read new_pincode
            echo "Enter the new state:"
            read new_state
            
            
            echo  $new_fname"\t\t\t"$new_lname"\t\t\t"$new_city"\t\t"$new_pincode"\t\t\t"$new_state >> $abfile
            
            
       else
            echo "Record not found"
            
      fi
     
}
            
      
      
main_menu 
      
      
