import React, { Component } from 'react';

import {
    ListView,
    View,
    Text,
    TextInput,
    Image,
    Button,
    AppRegistry
} from 'react-native';

import Style from './Style';
import Row from './components/Row'

{/*https://github.com/andersr/react-native-list-view-demo/blob/master/index.ios.js*/}
{/*https://medium.com/differential/react-native-basics-how-to-use-the-listview-component-a0ec44cf1fe8#.p9xz313nn*/}



class ListViewImage extends Component {
    constructor(props) {
        super(props);

        const ds = new ListView.DataSource({
            rowHasChanged: (r1, r2) => r1 !== r2
        });

        {/* const { dataBlob, rowIds } = this.getImages(); 
            define a function that collects all the data. */}

        this.state = {
            dataSource: ds.cloneWithRows(['row 1', 'row 2', 'row 3', 'row 4']),
        };
    }
    render() {
        return (
        <ListView
            style={Style.container}
            dataSource={this.state.dataSource}
            renderRow={(data) => <Row {...data} />}
        />
        );
    } 
}


class ImageProcessor extends Component {
    blur() {
        alert('Blur');
    }
    sharpen() {
        alert('Sharpened');
    }
    getImage() {
        alert('Got image');
    }

    render() {
        return (
        <View style={Style.rootContainer}>
            <Image 
                source={{uri: 'https://facebook.github.io/react/img/logo_og.png'}} 
                style={Style.imageContainer}
            />
            <View style={Style.displayContainer}>
                <View style={Style.buttonContainer}>
                    <Button
                        onPress={this.blur.bind(this)}
                        title="Blur"
                        color="steelblue"
                    />
                </View>
                <View style={Style.buttonContainer}>
                    <Button
                        onPress={this.sharpen.bind(this)}
                        title="Sharpen"
                        color="steelblue"
                    />
                </View>
            </View>
            <View style={Style.getImageContainer}>
                <TextInput
                    placeholder="Enter image id to retrieve"
                    blurOnSubmit={true} 
                    returnKeyType={"done"}
                    style={Style.textBox}
                    onSubmitEditing={this.getImage.bind(this)}
                />
            </View>
        </View>
        )
    }
}
            
AppRegistry.registerComponent('ImageProcessor',() => ListViewImage);
   
