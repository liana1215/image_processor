import { StyleSheet } from 'react-native';

var Style = StyleSheet.create({
    rootContainer: {
        flex: 1
    },

    imageContainer: {
        flex: 3,
        backgroundColor: '#FFFFFF',
        justifyContent: 'center'
    },

    displayContainer: {
        flex: 1,
        flexDirection: 'row',
        backgroundColor: '#193441',
        justifyContent: 'flex-end'
    },

    getImageContainer: {
        flex: 1,
        flexDirection: 'column',
        backgroundColor: '#FFFFFF',
        justifyContent: 'flex-end'
    },

    buttonContainer: {
        flex: 1,
        alignItems: 'stretch'
    },

    textBox: {
        height: 100,
        borderColor: 'gray',
        borderWidth: 1,
    },
});

export default Style;


