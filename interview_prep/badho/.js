// App.s

import React from 'react';
import {View,Text,Button} from 'react-native';

//implement custom hook to get prev value of counter
// function usePrevious(value){
//     const ref = React.useRef();
//     React.useEffect(()=>{
//         ref.current = value;
//     },[value]);
//     return ref.current;
// }

const usePrevCounter = ()=>{
    const [prevCounter, setPrevCounter]= React.useState(0);

    return {prevCounter};

} 

const App = () => {
    const [counter,setCounter] = React.useState(0);
    function increment(){
        setCounter(counter+1);
    }

  return (
    <View>
    <Text>{counter}</Text>
    <Button label="Increment" onPress={increment} />
    </View>
  );
};